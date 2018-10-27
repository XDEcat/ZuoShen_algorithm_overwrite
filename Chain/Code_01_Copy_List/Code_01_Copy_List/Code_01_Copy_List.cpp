//
//  main.cpp
//  Code_01_Copy_List
//
//  Created by 陈泰文 on 2018/10/24.
//  Copyright © 2018年 twchen. All rights reserved.
//


    Space O(N): hash_map/unordered_map

            Construct a hash_map<Node*, Node*>.
            while (ptr != nullptr) {
                Node* pOld = ptr;
                Node* pNew = new Node(ptr -> value);
                But each pNew -> next = nullptr.
                hash_map[pOld] = pNew;
            }
            while (ptr != nullptr) {
                hash_map[ptr] -> next = hash_map[ptr -> next];
            }
            return hash_map[head];


    Space O(1): Construct a integrate chain,
                then split old chain and new chain.

            while (ptr != nullptr) {
                new Node(ptr -> value);
                Insert new Node between ptr and ptr -> next.
                Split old chain and new chain.
            }
