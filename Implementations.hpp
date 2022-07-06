template<typename F_T,typename S_T>
bool Hash_Table<F_T,S_T>::empty() const {
    if(!size){
        return true;
    }
    return false;

}

template<typename F_T,typename S_T>
int Hash_Table<F_T,S_T>::hash_function(F_T key) {
    return key % number_of_hash_groups;
}

template<typename F_T,typename S_T>
void Hash_Table<F_T,S_T>::insert(F_T key,S_T value){
    int hash_value = hash_function(key);
    auto& cell = table[hash_value];
    bool key_exists = false;
    for(auto it = cell.begin();it!=cell.end();++it){
        if(it->first == key){
            key_exists = true;
            it->second = value;
            cout<<"[WARNING]: VALUE WAS REPLACED"<<endl;
            break;
        }
    }
    if(!key_exists){
        ++size;
        cell.emplace_back(key, value);
    }
}
template<typename F_T,typename S_T>
void Hash_Table<F_T,S_T>::remove(F_T key) {
    int hash_value = hash_function(key);
    auto& cell = table[hash_value];
    bool key_exists = false;
    for(auto it = cell.begin();it!=cell.end();++it){
        if(it->first == key){
            key_exists = true;
            it = cell.erase(it);
            --size;
            cout<<"[INFO]: ITEM WAS REMOVED"<<endl;
            break;
        }
    }
    if(!key_exists){
        cout<<"[WARNING]: VALUE WAS NOT REMOVED"<<endl;
    }
}

template<typename F_T,typename S_T>
string Hash_Table<F_T,S_T>::search(F_T key) {
    int hashValue = hash_function(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            return bItr->second;
        }
    }

    if (!keyExists)
        return "RESULT WAS  Not FOUND";
}

template<typename F_T,typename S_T>
void Hash_Table<F_T,S_T>::print() {
    for(int i = 0;i<number_of_hash_groups;++i){
        if(table[i].size() == 0)continue;
        for(auto it = table[i].begin();it!=table[i].end();++it){
            cout<<"[INFO]: KEY: "<<it->first<<"\t"<<"VALUE: "<<it->second<<endl;
        }
    }
}


