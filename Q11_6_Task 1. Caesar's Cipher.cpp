#include <iostream>
#include <string>

	bool ok = false;
	std::string code, str, codeKey, newStr;
	int i, j, counting;

void output()
{
	if (ok)
	{
		std::cout << "Result: " << newStr << "\n";
	}
}

void input_code()
{
		std::cout << "Code: ";
		std::cin >> code;

	for (i = 0; i < code.length(); i++)
	{
		if ((code[0] > 48) && ((code[i] >= 48) && (code[i] <= 57)))
		{
				codeKey +=code[i];
				ok = true;
		}
		else if ((code[i] < 49)||(code[i] > 57))
		{
			codeKey = "";
			input_code();
		}
	}
}


bool doingThings( bool ch)
{
	for (i = 0; i < str.length(); i++)
	{
		if (((str[i] < 65)||(str[i] > 90))&&((str[i] < 97)||(str[i] > 122)))
		{
			newStr += str[i];	
		}
		else if ((str[i] >= 65)&&(str[i] <= 90))
		{
			counting = str[i];
			for (j = 1; j <= stoi(codeKey); j++)
			{
				counting++;
				if ((counting == 91))
				{
					counting = 65;
				}
			}
		newStr += counting;
		}	
		else if ((str[i] >= 97)&&(str[i] <= 122))
		{
			counting = str[i];
			for (j = 1; j <= stoi(codeKey); j++)
			{
				counting++;
				if ((counting == 123))
				{
					counting = 97;
				}
			}
		newStr += counting;
		}		
	}
	return ch;
}

int main()
{
	std::cout << "Text: ";
	std::getline (std::cin, str);

	input_code();
	doingThings(true);
	output();

}    