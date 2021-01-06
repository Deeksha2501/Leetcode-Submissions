class Solution {
public:
    bool b_find(int num){
	int bmonth[7] = {1 , 3 , 5 , 7, 8, 10 , 12};
	for(int i=0 ; i<7 ; i++){
		if(bmonth[i] == num)
		return true;
	};
	return false;
}
    
    bool s_find(int num ){
	int smonth[4] = {4 , 6 , 9 , 11};
	for(int i=0 ; i<4 ; i++){
		if(smonth[i] == num)
		return true;
	}
	return false;
}
    
    int split(string s){
	char arr[3][4];
	int k = 0 , j=0;
	for(int i=0 ; i<s.length() ; i++){
		if(s[i] == '-'){
			k++;
			j=0;
			continue;
		}
		arr[k][j] = s[i];
		j++;
	}


    string date = ""; 
    date += arr[2][0];
	date += arr[2][1];
	
	string month = "";
	month += arr[1][0];
	month += arr[1][1];
	
    string year = "";
    year += arr[0][0];
    year += arr[0][1];
	year += arr[0][2];
	year += arr[0][3];
		
    stringstream d(date); 
    stringstream m(month); 
    stringstream y(year);
    
    
    int x = 0 , mon =0 , yr=0; 
    d >> x; 
    m >> mon;
    y >> yr;
    int days = 0;
    for(int i=1 ; i<=mon-1 ; i++){
    	if(b_find(i)){
    		days += 31;
		}else if(s_find(i)){
			days += 30;
		}
		else if(i == 2){
			if(yr%4 == 0 && yr%100 != 0){
				days += 29;
			}
			else{
			days += 28;
		}
		}

	}
   days += x;
   
    return days; 
    }
    
    int dayOfYear(string date) {
        return split(date);
        
    }
};