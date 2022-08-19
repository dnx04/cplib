# Generic Implicit Treap (Splay Tree)

## Example
```cpp
template <class K,            // key
          class S,            // node aggregate data
          S (*op)(S, K, S),   // for recomputing data of a node
          pair<K, S> (*e)(),  // identity data
          class F,            // lazy propagation tag
          pair<K, S> (*mapping)(F, node_t<K, S, F> *),  // apply tag F on a node
          F (*composition)(F, F),                       // combine 2 tags
          F (*id)()                                     // identity tag
          >
```