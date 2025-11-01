template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int probes = 0;
    for (int i = 0; i < M; i++) {
        probes++;
        int index = probeIndex(key, i);

        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = true;
            N++;
            return probes;
        }
    }
    return probes;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    int probes = 0;
    for (int i = 0; i < M; i ++) {
        probes++;
        int index = probeIndex(key, i);

        if (!occupied[index]) {
            return {false, probes};
        }

        if (table[index] == key) { 
            return {true, probes};  
        }
    }
    return {false, probes};
}
