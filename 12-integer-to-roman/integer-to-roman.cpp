class Solution {
public:
    string intToRoman(int num) 
    {
        string ones[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hndr[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thsd[]={"","M","MM","MMM"};

        return thsd[num/1000]+hndr[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];
    
    }
};