#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <map>
#include "readerhelper.h"
#define CURRENT_MINE_REWARD 12.5 // as of May-2017
#define CURRENT_BLOCK_WEIGHT 1000000
/*
*	Compare and return max.
*/
const double return_max(const double a, const double b)
{
	return (a > b)? a : b;
}
/*
*	A recursive helper function for Bitcoin Bucket fee Optimization using 0/1 Knapsack approach.
*/
double BucketTxnSum(const std::vector<std::vector<double> > &BlockTxnFee, const size_t maxblocksize, size_t txn_index, std::map<size_t, std::pair<size_t, double> > memTxnCache)
{
	double total_fee = 0.0;
	size_t block_weight_delta = BlockTxnFee[txn_index][1];
	if(memTxnCache[txn_index].first == maxblocksize){
		return memTxnCache[txn_index].second;
	}
	if (maxblocksize == 0 || txn_index == 0){
		return 0.0;
	}
	else if(block_weight_delta < maxblocksize){
		total_fee =  return_max(BlockTxnFee[txn_index][2] + BucketTxnSum(BlockTxnFee, maxblocksize - block_weight_delta, txn_index - 1, memTxnCache), 
			BucketTxnSum(BlockTxnFee, maxblocksize, txn_index - 1, memTxnCache) );
	} else {
		total_fee =  BucketTxnSum(BlockTxnFee, maxblocksize, txn_index - 1, memTxnCache); 
	}
	memTxnCache[txn_index] = std::make_pair(maxblocksize, total_fee);
	return total_fee;
}
/*
*	Optimal Fee Computation.
*/
double FindOptimalFee(std::vector<std::vector<double> > &BlockTxnFee, size_t blocksize)
{
	size_t txn_count = BlockTxnFee.size();
	std::map<size_t, std::pair<size_t, double> > memTxnCache;
	double fee = BucketTxnSum(BlockTxnFee, blocksize, txn_count - 1, memTxnCache);
	return fee;
}

int main(void)
{
	TextReader<double> block_data_parser("input.txt");
	std::vector<std::vector<double> > BlockTxnFee = block_data_parser.parseReturnData();
	double OptimalFee = FindOptimalFee(BlockTxnFee, CURRENT_BLOCK_WEIGHT);
	std::cout << "Total Mine Reward : " << CURRENT_MINE_REWARD + OptimalFee << std::endl;
	std::cout << "Fee-Only Reward : " << OptimalFee << std::endl;
	return 0;
}
