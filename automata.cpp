#include <iostream>
#include "automata.h"

using namespace std;

/**
 * Constructor for Abstract DFA.
 * 
 * @param noStates
 *            Number of states in the DFA.
 */
AbstractDFA::AbstractDFA(int noStates) : numStates(noStates), actState(initialState){}

/**
 * Reset the automaton to the initial state.
 */
void AbstractDFA::reset() { actState = initialState; }

/**
 * Performs one step of the DFA for a given letter. If there is a transition
 * for the given letter, then the automaton proceeds to the successor state.
 * Otherwise it goes to the sink state. By construction it will stay in the
 * sink for every input letter.
 * 
 * @param letter
 *            The current input.
 */
void AbstractDFA::doStep(char letter) {
    //Controllo per verificare
    //Check to verify that the current state does not correspond to the trap state, otherwise there is no point in proceeding
    if(actState != trapState){
        //Creo l'iteratore corrispondente allo stato attuale
        map<tpair, int>::iterator ftran = transitionF.find(tpair(actState,letter));
        //Devo verificare de l'iteratore si trova in uno stato valido, altrimenti
        if(ftran != transitionF.end()){
            //Scorro al prossimo elemento

        }else{
            actState = trapState;
        }
    }
}

/**
 * Check if the automaton is currently accepting.
 * 
 * @return True, if the automaton is currently in the accepting state.
 */
bool AbstractDFA::isAccepting() {
   return actState
}

/**
 * Run the DFA on the input.
 * 
 * @param inputWord
 *            stream that contains the input word
 * @return True, if if the word is accepted by this automaton
 */
bool AbstractDFA::run(const string &inputWord) {
    this->reset();
    for(int i = 0; i < inputWord.length(); i++) {
        doStep(inputWord[i]);
    }
    return isAccepting();
}


/**
 * Construct a new DFA that recognizes exactly the given word. Given a word
 * "foo" the constructed automaton looks like: -> () -f-> () -o-> () -o-> []
 * from every state (including the final one) every other input letter leads
 * to a distinguished sink state in which the automaton then remains
 * 
 * @param word
 *            A String that the automaton should recognize
 */
WordDFA::WordDFA(const string &word) : AbstractDFA(0) {
    // TODO: fill in correct number of states
    
    // TODO: build DFA recognizing the given word
}

/**
 * Construct a new DFA that recognizes comments within source code. There
 * are three kinds of comments: single line comment that starts with // and ends
 * with a newline, multiline comments that starts with (* and ends with *), and
 * multiline comments that starts with { and ends with }
 */
CommentDFA::CommentDFA() : AbstractDFA(0) {
    // TODO: fill in correct number of states
    // TODO: build DFA recognizing comments
}

/**
 * Performs one step of the DFA for a given letter. This method works
 * differently than in the superclass AbstractDFA.
 * 
 * @param letter
 *            The current input.
 */
void CommentDFA::doStep(char letter) {
    // TODO: implement accordingly
}	

