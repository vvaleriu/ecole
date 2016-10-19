//
// Created by vincent on 29/09/16.
//

#include "AAlgorithm.hpp"

/*
 * ============================
 * 		PUBLIC METHODS
 * ============================
 * */

/*
* ---- CONSTRUCTORS ----
* */
AAlgorithm::AAlgorithm(PQ &open, PQ &close, State &final) : open(open), close(close), final(final) {}

AAlgorithm::~AAlgorithm(void) {}
/*
* ============================
* 		PRIVATE METHODS
* ============================
* */
