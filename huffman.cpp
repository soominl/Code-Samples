/*
    Code Samples
    Author: Soomin Lee
    Language: C++
*/


    /*
        This C++ code is part of compressing algorithm;
        it uses Huffman Tree to compress and decompress files.
        Below method builds a Huffman coding trie


     *  Use the Huffman algorithm to build a Huffman coding trie.
     *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
     *  the frequency of occurrence of byte i in the message.
     *  POSTCONDITION:  root points to the root of the trie,
     *  and leaves[i] points to the leaf node containing byte i.
     */
    void HCTree::build(const vector<int>& freqs){

    	/* initialize priority queue for the tree */
        std::priority_queue<HCNode *, std::vector<HCNode *>, HCNodePtrComp> pq;

        /* create nodes */
    	for(int pos = 0; pos < freqs.size(); pos++){
    		if(freqs[pos] != 0){
    			HCNode * temp = new HCNode(freqs[pos], pos, 0, 0, 0);
    			leaves[pos] = temp;
                pq.push(temp);
    		}
    	}

        /* only one leaf = root */
    	if(pq.size() == 1){
    		root = pq.top();
    		pq.pop();
            
    	}else{

    	   while(pq.size() > 1){

                /* Pick the two elements that have the highest priority in pq */
                HCNode* node1 = pq.top();
                pq.pop();
                HCNode* node2 = pq.top();
                pq.pop(); 
                int sum = node1->count + node2->count;

                /* make temp parent node for node1 and node 2 */
                HCNode* tempNode = new HCNode(sum, node1->symbol, node1, node2, nullptr);

                /* set the parent node */
                node1 -> p = tempNode;
                node2 -> p = tempNode;

                /* connect temp parent to children */
                tempNode -> c0 = node1;
                tempNode -> c1 = node2;
                
                /* add to the tree */
                pq.push(tempNode);

    	   }

            /* set the root node */
            root = pq.top();
        }

    }
