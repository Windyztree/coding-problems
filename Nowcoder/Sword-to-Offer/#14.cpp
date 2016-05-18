class Solution {
public:
    bool isNumeric(char* string)
    {
        int flagE = 0;
        int flagPoint = 0;
        bool hasPoint = false;
        bool hasE = false;
        if (string[0] == '.')
            return false;
        for (int i = 0; string[i] != '\0'; ++i){
            if (!isNum(string[i]) && string[i] != '+' && string[i] != '-' && string[i] != 'e' && string[i] != 'E' && string[i] != '.')
                return false;
            if (string[i] == 'e' || string[i] == 'E')
                flagE++;
            if (string[i] == '.')
                flagPoint++;
        }
        if (flagE >1 || flagPoint > 1)
            return false;
        if (*string == '+' || *string == '-'){
            ++string;
            if (*string == '+' || *string == '-' || *string == '\0')
                return false;
        }
        int locE;
        for (int i = 0; string[i] != '\0'; ++i){
            if (string[i] == '.')
                hasPoint = true;
            if (string[i] == 'e' || string[i] == 'E'){
                hasE = true;
                locE = i;
            }
        }
        if (!hasE){
            for (int i = 0; string[i] != '\0'; ++i){
            	if (string[i] == '+' || string[i] == '-')
                	return false;
            }
            return true;
        }
        else{
            if (string[locE + 1] == '\0')
                return false;
            for (int i = 0; string[i] != '\0'; ++i){
                if (string[i] == '+' || string[i] == '-')
                    if (i != locE + 1)
                        return false;
            }
            if (hasPoint)
                for (int i = 0; string[i] != '\0'; ++i){
                    if (string[i] == '.')
                        if (i >= locE - 1)
                            return false;
            }
            return true;
        }
    }
    
    bool isNum(char ch)
    {
        if (ch < '0' || ch > '9')
            return false;
        return true;
    }
};
