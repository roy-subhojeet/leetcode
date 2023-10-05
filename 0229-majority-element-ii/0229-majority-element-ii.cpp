class Solution {
public:
  vector<int> majorityElement(vector<int> &a) 
  {
	  int candidateA(-1), candidateB(-1), countA(0), countB(0);
    
	  for (const auto & elem: a) 
	  {
		  if (elem == candidateA) countA++;
		  else if (elem == candidateB) countB++;
		  else if (! countA) candidateA = elem, countA = 1;
		  else if (! countB) candidateB = elem, countB = 1;
		  else countA--, countB--;
     }
      
     countA = countB = 0;
     for (const auto & elem: a)
		 if (elem == candidateA) countA++;
		 else if (elem == candidateB) countB++;
  
	  vector<int> r;
	  if (countA > size(a)/3) r.push_back(candidateA);
	  if (countB > size(a)/3) r.push_back(candidateB);
	  return r;
  }
};