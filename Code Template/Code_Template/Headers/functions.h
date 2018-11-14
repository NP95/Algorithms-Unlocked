/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef functions_h
#define functions_h
#include "static.h"
#include "methods.h"
#include "constants.h"
using namespace std;

void copy_codechef()
{
    std::string str;
    freopen(MAIN, "r+", stdin);
    freopen(STDOUT_CODECHEF_REDIRECT, "a+", stdout);
    std::getline(std::cin, str);
    while(std::getline(std::cin, str)){
        printf("%s\n", str.c_str());
    }
}

template <typename T>
struct DfiniteAutomaton{
	map<T, map<T, T> > transition_table;
	unordered_set<T> final_states, all_states, input_symbols;
	T start_state;
};

template <typename T>
void ConstructDFA(DfiniteAutomaton<T>& DFA, unsigned int states, unsigned int symbols)
{
	T input;
	cout << "Enter all valid states of the DFA. " << states << ", in number." << endl;
	for(unsigned int i = 0; i < states; i++){
		cin >> input;
		DFA.all_states.insert(input);
	}

	cout << "Enter all valid symbols accepted by DFA. " << symbols << ", in number." << endl;
	for(unsigned int i = 0; i < symbols; i++){
		cin >> input;
		DFA.input_symbols.insert(input);
	}

	for(const auto current_state : DFA.all_states){
		for(const auto symbol : DFA.input_symbols){
			cout << endl << "On state : " << current_state << " seeing symbol : " << symbol << ", please enter what happens? : ";
			cin >> input;
			while(DFA.all_states.find(input) == DFA.all_states.end()){
				cout << "Invalid state entered. Enter again : " << endl;
				cin >> input;
			}	
			DFA.transition_table[symbol][current_state] = input;
		}
	}

	for(unsigned int i = 0; i < states; i++){
		cout << "Enter final states : ";
 		cin >> input;
		while(DFA.all_states.find(input) == DFA.all_states.end()){
			cout << "Invalid state entered. Enter again : " << endl;
			cin >> input;
		}
		DFA.final_states.insert(input);
	}


	for(const auto current_state : DFA.all_states){
		for(const auto symbol : DFA.input_symbols){
				cout << white << "On symbol," << green << symbol << white << " at State," << red << current_state << white << " Next State : " << yellow << DFA.transition_table[symbol][current_state] << endl;
		}
	}
}

#endif /* functions_h */
