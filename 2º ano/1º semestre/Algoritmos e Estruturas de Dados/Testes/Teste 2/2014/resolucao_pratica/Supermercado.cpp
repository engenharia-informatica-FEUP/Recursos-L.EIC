/*
 * Supermercado.cpp
 *
 * Created on: Dec 3, 2014
 *
 */

#include "Supermercado.h"

int Cliente::numeroItens() const{
	int result = 0;
	for(list<Cesto>::const_iterator it = cestos.begin(); it != cestos.end(); it++)
		result += it->getItens().size();
	return result;
}

int Cliente::valorItens() const{
	int result = 0;
	for(list<Cesto>::const_iterator it = cestos.begin(); it != cestos.end(); it++){
			stack<Item> itens = it->getItens();
			unsigned int size = itens.size();
			for(unsigned int i = 0; i < size; i++){
				result += itens.top().preco;
				itens.pop();
			}
	}
	return result;
}

int Cliente::trocarItem(Item& novoItem){
	int counter = 0;
	for(list<Cesto>::iterator it = cestos.begin(); it != cestos.end(); it++){
		vector<Item> newItens;
		int size = it->getItens().size();
		while(size > 0){
			if(it->getItens().top().preco > novoItem.preco || it->getItens().top().produto == novoItem.produto){
			//if(it->getItens().top().preco > novoItem.preco && it->getItens().top().produto == novoItem.produto){ - correct, not working version
				newItens.push_back(novoItem);
				counter++;
			}
			else
				newItens.push_back(it->getItens().top());
			it->popItem();
			size--;
		}
		for(unsigned int i = 0; i < newItens.size(); i++)
			it->pushItem(newItens.at(newItens.size()-1-i));
	}
	return counter;
}

bool Item::operator<(const Item &i1){
	return peso < i1.peso;
}

void Cliente::organizarCestos(){
	for(list<Cesto>::iterator it = cestos.begin(); it != cestos.end(); it++){
		stack<Item> itens = it->getItens();
		vector<Item> toSort;
		unsigned int size = itens.size();
		for(unsigned int i = 0; i < size; i++){
			toSort.push_back(itens.top());
			itens.pop();
			it->popItem();
		}
		sort(toSort.begin(),toSort.end());
		for(unsigned int i = 0; i < toSort.size(); i++)
			it->pushItem(toSort.at(toSort.size()-1-i));
	}
}

vector<string> Cliente::contarItensPorTipo(){
	vector<pair<string,int>> pares;
	for(list<Cesto>::iterator it = cestos.begin(); it != cestos.end(); it++){
		stack<Item> itens = it->getItens();
		unsigned int size = itens.size();
		while(size > 0){
			Item currentItem = itens.top();
			bool found = false;
			unsigned int i;
			for(i = 0; i < pares.size(); i++){
				if(pares.at(i).first == currentItem.tipo){
					found = true;
					break;
				}
			}
			if(found)
				pares.at(i).second++;
			else
				pares.push_back(pair<string,int>(currentItem.tipo,1));
			itens.pop();
			size--;
		}
	}
	vector<string> result;
	for(unsigned int i = 0; i < pares.size(); i++)
		result.push_back(pares.at(i).first+" "+to_string(pares.at(i).second));
	return result;
}

int Cesto::novoItem(const Item& umItem){
	stack<Item> itensTemp = itens;
	int size = itensTemp.size();
	int weight = 0, volume = 0;
	while(size > 0){
		weight += itensTemp.top().peso;
		volume += itensTemp.top().volume;
		itensTemp.pop();
		size--;
	}
	if(umItem.peso+weight>max_peso || umItem.volume+volume>max_volume)
		return 0;
	pushItem(umItem);
	return itens.size();
}

int Cliente::novoItem(const Item& umItem){
	bool done = false;
	for(list<Cesto>::iterator it = cestos.begin(); it != cestos.end(); it++){
		if(it->novoItem(umItem) != 0){
			done = true;
			break;
		}
	}
	if(!done){
		vector<Item> soloItem;
		soloItem.push_back(umItem);
		Cesto *c1 = new Cesto(soloItem);
		return addCesto(*c1);
	}
	else
		return cestos.size();
}

int Supermercado::novoCliente(Cliente& umCliente){
	if(umCliente.getIdade() < 65 || (umCliente.getIdade() >= 65 && getFilaNormal().size() < getFilaPrioritaria().size())){
		queue<Cliente> newClients = getFilaNormal();
		newClients.push(umCliente);
		setFilaNormal(newClients);
		return getFilaPrioritaria().size()+getFilaNormal().size();
	}
	else{
		queue<Cliente> newClients = getFilaPrioritaria();
		newClients.push(umCliente);
		setFilaPrioritaria(newClients);
		return getFilaPrioritaria().size()+getFilaNormal().size();
	}

}

Cliente Supermercado::sairDaFila(string umNomeDeCliente){
	queue<Cliente> filaNormal = getFilaNormal();
	queue<Cliente> filaPrioritaria = getFilaPrioritaria();
	unsigned int size = filaNormal.size();
	vector<Cliente> vn;
	vector<Cliente> vp;
	while(size > 0){
		if(filaNormal.front().getNome() == umNomeDeCliente){
			Cliente returnValue = filaNormal.front();
			filaNormal.pop();
			size--;
			while(size > 0){
				vn.push_back(filaNormal.front());
				filaNormal.pop();
				size--;
			}
			queue<Cliente> fn;
			for(unsigned int i = 0; i < vn.size(); i++)
				fn.push(vn.at(i));
			setFilaNormal(fn);
			return returnValue;
		}
		vn.push_back(filaNormal.front());
		filaNormal.pop();
		size--;
	}
	size = filaPrioritaria.size();
	while(size > 0){
		if(filaPrioritaria.front().getNome() == umNomeDeCliente){
			Cliente returnValue = filaPrioritaria.front();
			filaPrioritaria.pop();
			size--;
			while(size > 0){
				vp.push_back(filaPrioritaria.front());
				filaPrioritaria.pop();
				size--;
			}
			queue<Cliente> fp;
			for(unsigned int i = 0; i < vp.size(); i++)
				fp.push(vp.at(i));
			setFilaPrioritaria(fp);
			return returnValue;
		}
		vp.push_back(filaPrioritaria.front());
		filaPrioritaria.pop();
		size--;
	}
	throw Supermercado::ClienteInexistente(umNomeDeCliente);
}
