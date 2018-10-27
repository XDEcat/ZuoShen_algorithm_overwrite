//
//  main.cpp
//  Code_00_Is_Palindrome_List
//
//  Created by 陈泰文 on 2018/10/24.
//  Copyright © 2018年 twchen. All rights reserved.
//



    Space O(N): stack

            Construct a help stack<Node*>.
            Push Node* into stack.
            while (ptr != nullptr) {
                if (ptr -> value != stack.top() -> value) {
                    return false;
                }
                ptr = ptr -> next;
                stack.pop();
            }
            return true;


    Space O(1): fast slow ptrs to find mid,
                three ptrs to reverse right chain.

            Construct two ptr: fast, slow.
            while (fast -> next != nullptr && fast -> next -> next != nullptr) {
                slow = slow -> next;
                fast = fast -> next -> next;
            }
            Now slow is the mid.
            fast = slow -> next;
            slow -> next = nullptr;
            Now fast is the head of right chain.
            Reverse right chain with three ptrs.
            Compare left chain and right chain.
            Reverse right chain again.
