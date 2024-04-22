#include <iostream>
#include <string>

std::string
str,
strNot,
address, 
addressTmp, 
result, 
localName,
localNamemustnot = "<>( )[]@,;:\\/*",
domainName,
domainNamemustnot = "<>()[]@,;:\\/*!#$%&';+=?^^_`{}|~";
int i, j, k = 0, dog, dots_and_separation(std::string);
bool go = true;

void output()
{
	if (go)
	{
		result = "Correct  IP address";
	}
	else
	{
		result = "Invalid IP address";
	}
	
	std::cout << result;
}

void input()
{
	std::cout << " IP address: ";
	std::getline(std::cin, address);
	addressTmp = address;
}

bool checking_dogs(bool ok)
{
	for ( i = 0; i < addressTmp.length(); i++)
	{
		if (addressTmp[i] == 64)
		{
			dog++;
		}
	}

	if (dog == 1)
	{
		dots_and_separation(addressTmp);
	}
	else
	{
		go = false;
	}

	return ok;
}

int dots_and_separation(std::string)
{
	if (go)
	{
		for (i = 0; i < addressTmp.length(); i++)
		{
			if ((addressTmp[i] == 46 && addressTmp[i + 1] == 46)
				|| (addressTmp[0] == 46 || addressTmp[addressTmp.length() - 1] == 46)
				|| (addressTmp[i] == 64 && addressTmp[i - 1] == 46)
				|| (addressTmp[i] == 64 && addressTmp[i + 1] == 46))
			{
				go = false;
				break;
			}
			else
			{
				go = true;
			}
		}
		if (go)
		{
			for (i = 0; i < addressTmp.length(); i++)
			{
				if (addressTmp[i] != 64)
				{
					localName += addressTmp[i];
					j = i + 2;
					if (localName.length() > 64)
					{
						go = false;
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (j = j; j < addressTmp.length(); j++)
			{
				domainName += addressTmp[j];
				if (domainName.length() > 63)
				{
					go = false;
					break;
				}
			}
		}

		if (k == 0)
		{
			str = localName;
			strNot = localNamemustnot;
		}
	}
	
	return 0;
}

void check_syntax()
{
	if (go)
	{
		for (i = 0; i < str.length(); i++)
		{
			for  ( j = 0; j < strNot.length(); j++)
			{
				if (strNot[j] == str[i])
				{
					go = false;
					break;
				}
			}
		}

		if ((go) && (k == 0))
		{
			str = domainName;
			strNot = domainNamemustnot;
			k = 1;
			check_syntax();
		}
	}
}

int main()
{
	input();
	checking_dogs(true);
	check_syntax();
	output();
}