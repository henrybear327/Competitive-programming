class Solution
{
private:
	bool isValid(int hh, int mm)
	{
		if (!(0 <= hh && hh <= 23))
			return false;
		if (!(0 <= mm && mm <= 59))
			return false;

		return true;
	}
    
    string print(int hh, int mm) 
    {
        string ans;
        
        if(hh < 10)
            ans += "0";
        ans += to_string(hh);
        ans += ":";
        if(mm < 10)
            ans += "0";
        ans += to_string(mm);
        
        return ans;
    }

public:
	string largestTimeFromDigits(vector<int> &A)
	{
		sort(A.begin(), A.end());
        int mhh = -1;
        int mmm = -1;

		do {
			int hh = A[0] * 10 + A[1];
			int mm = A[2] * 10 + A[3];
            
            // cout << hh << " " << mm << " " << (isValid(hh, mm) ? "true" : "false") << endl;

			if (isValid(hh, mm) && (hh > mhh || (hh == mhh && mm >= mmm))) { // what a good question
                mhh = hh;
                mmm = mm;
			} 
		} while (next_permutation(A.begin(), A.end()));


        return (mhh == -1 ? "" : print(mhh, mmm));
	}
};
