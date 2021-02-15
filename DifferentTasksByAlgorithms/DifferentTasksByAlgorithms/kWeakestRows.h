/*
* Input:		Given a m * n matrix mat of ones and zeros, and int k
* Output:		the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.
*
* Note :	A row i is weaker than row j, if the number of ones in row i is less than the number of ones in row j,
*			or they have the same number of soldiers but i is less than j. Ones are always stand in the frontier of a row,
*			that is, always ones may appear first and then zeros.
*/