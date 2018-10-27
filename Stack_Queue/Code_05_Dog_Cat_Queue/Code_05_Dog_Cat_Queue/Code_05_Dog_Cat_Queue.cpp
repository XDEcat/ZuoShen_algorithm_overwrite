//
//  main.cpp
//  Code_05_Dog_Cat_Queue
//
//  Created by 陈泰文 on 2018/10/23.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Pet {
    string type;

public:
    Pet (string pet_type) : type(pet_type) {}
    
    string getType() {
        return this -> type;
    }
};

class Dog : public Pet {
public:
    Dog() : Pet("Dog") {}
};

class Cat : public Pet {
public:
    Cat() : Pet("Cat") {}
};

class PetIndex {
    Pet pet;
    int index;
    
public:
    PetIndex(Pet pet, int index) : pet(pet), index(index) {
        cout << pet.getType() << " ";
    }
    
    Pet getPet() {
        return pet;
    }
    
    int getIndex() {
        return index;
    }
    
    string getPetType() {
        return pet.getType();
    }
};

class DogCatQueue {
    queue<PetIndex> dogQueue;
    queue<PetIndex> catQueue;
    int index;
    
public:
    DogCatQueue() {
        index = 0;
    }
    
    void push(Pet pet) {
        if (pet.getType() == "Dog") {
            dogQueue.push(*new PetIndex(pet, index++));
        }
        if (pet.getType() == "Cat") {
            catQueue.push(*new PetIndex(pet, index++));
        }
    }
    
    bool isDogQueueEmpty() {
        return dogQueue.empty();
    }
    
    bool isCatQueueEmpty() {
        return catQueue.empty();
    }
    
    bool isDogCatQueueEmpty() {
        return dogQueue.empty() && catQueue.empty();
    }
    
    Dog pollDog() {
        if (!this -> isDogQueueEmpty()) {
            Pet temp= dogQueue.front().getPet();
            dogQueue.pop();
            Dog res;
            Pet* p = &res;
            *p = temp;
            return res;
        } else {
            throw "Dog queue is empty!\n";
        }
    }
    
    Cat pollCat() {
        if (!this -> isCatQueueEmpty()) {
            Pet temp = catQueue.front().getPet();
            catQueue.pop();
            Cat res;
            Pet* p = &res;
            *p = temp;
            return res;
        } else {
            throw "Cat queue is empty!\n";
        }
    }
    
    Pet pollAll() {
        if (!this -> isCatQueueEmpty() && !this -> isDogQueueEmpty()) {
            if (dogQueue.front().getIndex() < catQueue.front().getIndex()) {
                Pet res = dogQueue.front().getPet();
                dogQueue.pop();
                return res;
            } else {
                Pet res = catQueue.front().getPet();
                catQueue.pop();
                return res;
            }
        } else if (!this -> isDogQueueEmpty()) {
            Pet res = dogQueue.front().getPet();
            dogQueue.pop();
            return res;
        } else if (!this -> isCatQueueEmpty()) {
            Pet res = catQueue.front().getPet();
            catQueue.pop();
            return res;
        } else {
            throw "All queue is empty!\n";
        }
    }
};

int main() {
    Dog dog1,dog2,dog3;
    Cat cat1,cat2,cat3;
    DogCatQueue DogCatQueue;
    cout << "Push in DogCatQueue: ";
    DogCatQueue.push(dog1);
    DogCatQueue.push(cat1);
    DogCatQueue.push(dog2);
    DogCatQueue.push(cat2);
    DogCatQueue.push(dog3);
    DogCatQueue.push(cat3);
    cout << endl;
    cout << "Poll dogs: ";
    while (!DogCatQueue.isDogQueueEmpty()) {
        cout << DogCatQueue.pollDog().getType() << " ";
    }
    cout << endl;
    cout << "Poll all pets: ";
    while (!DogCatQueue.isDogCatQueueEmpty()) {
        cout << DogCatQueue.pollAll().getType() << " ";
    }
    cout << endl;
    return 0;
}
