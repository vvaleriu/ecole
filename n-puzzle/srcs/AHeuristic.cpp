//
// Created by vincent on 02/08/16.
//

#include "AHeuristic.hpp"

/*
 * ============================
 * 		PUBLIC METHODS
 * ============================
 * */

/*
* ---- CONSTRUCTORS ----
* */
AHeuristic::AHeuristic(State& finalState) : final(finalState) {}
AHeuristic::~AHeuristic(void) {}

/*
* ---- ACCESSORS ----
* */
State &AHeuristic::getFinal() const {return final;}

/*
* ============================
* 		PRIVATE METHODS
* ============================
* */
