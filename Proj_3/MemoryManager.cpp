//-----------------------------------------------------------------------------
// MemoryManager.cpp                                             Project 3
//-----------------------------------------------------------------------------

#include <cassert>
#include <iostream>
#include "dlUtils.h"
#include "MemoryManager.h"

MemoryManager::MemoryManager(unsigned int memtotal): memsize(memtotal)
{
   baseptr = new unsigned char[memsize];
   blockdata originalBlock(memsize, true, baseptr);
   firstBlock = new dlNode<blockdata>(originalBlock,nullptr,nullptr);
}

void MemoryManager::showBlockList() 
{
	printDlList(firstBlock,"->");
}

void MemoryManager::splitBlock(dlNode<blockdata> *p, unsigned int chunksize) 
{
	// Creating next block
	int memPool = p->info.blocksize - chunksize;
	unsigned char *nextBlockPtr = new unsigned char[memPool];
	blockdata nextBlock(memPool, true, nextBlockPtr);

	//Insertion
	insertAfter(firstBlock, p, nextBlock);

	//Changing block information
	p->info.free = false;
	p->info.blocksize = chunksize;

}

unsigned char * MemoryManager::malloc(unsigned int request)
{
	dlNode<blockdata>* current = firstBlock; //Placeholder for firstBlock
	while (current != nullptr)
	{
		//Checks to see if request is too large
		if (current->info.free && current->info.blocksize < request)
			return nullptr;

		//If available, splitBlock
		if (current->info.free && current->info.blocksize > request){
			splitBlock(current, request);
			return current->info.blockptr;
		}
		//If same size, change free flag and return ptr
		if (current->info.free && current->info.blocksize == request) {
			current->info.free = false;
			return current->info.blockptr;
		}
		current = current->next;// Moves to next node
	}
}

void MemoryManager::mergeForward(dlNode<blockdata> *p)
{ 
	dlNode<blockdata>* hold = p; //holds block to be merged

	//Scans through nodes until nullptr, looking for free nodes
	while (p != nullptr) {       
		if (p->info.free == true) {
			p->info.blocksize += hold->info.blocksize; //adds blocksize to free block
		}
		p = p->next; 
	}

}

void MemoryManager::mergeBackward(dlNode<blockdata> *p)
{ 
	dlNode<blockdata>* hold = p; //holds block to be merged

	//Scans through nodes until nullptr, looking for free nodes
	while (p != nullptr) {
		if (p->info.free == true) {
			p->info.blocksize += hold->info.blocksize;
		}
		p = p->prev;
	}

}

void MemoryManager::free(unsigned char *ptr2block)
{ 
	dlNode<blockdata>* current = firstBlock; //Placeholder for firstBlock

	//Scans through nodes looking for ptr2block match
	while (current != nullptr) {
		if (current->info.blockptr == ptr2block) {
			mergeForward(current);
			mergeBackward(current);
			deleteNode(firstBlock, current); //deletes node after merges
			break;
		}
		current = current->next;
	}
}


