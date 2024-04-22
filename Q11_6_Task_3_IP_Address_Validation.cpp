#include <iostream>
#include <string>

std::string address, addressTmp, result, octet;
int i, j = 0, afterZero = 0, dots;
bool octets(bool fine);

void output()
{
	std::cout << result;
}

void input()
{
	std::cout << "IP address: ";
	std::getline(std::cin, address);
	addressTmp = address + ".";
	for ( i = 0; i < address.length(); i++)
	{
		if (((address[i] == 46) && (address[i + 1] == 46)) || address[0] == 46 || address[address.length() - 1] == 46)
		{
			result = "Invalid IP address";
			afterZero = 1;
		}
	}
}

bool octets(bool fine)
{
	for (i = 0; i < addressTmp.length(); i++)
	{
		if (addressTmp[i] != 46)
		{
			octet += addressTmp[i];
			addressTmp.erase(i, 1);
			i--;
			
		}
		else if (addressTmp[i] == 46)
		{
			if (octet.length() > 3 || (octet.length() >= 2 && (octet[0] == 48 && octet[1] >= 48)))
			{
				result = "Invalid IP address";
				dots = 5;
				afterZero = 1;
					break;
			}
			dots++;
			for (j = 0; j < octet.length(); j++)
			{
				if ((octet[j] < 48 || octet[j] > 57) || (stoi(octet) > 255 || stoi(octet) < 0) || (octet[0] == 48 && octet[1] >= 48))
				{
					result = "Invalid IP address";
				}
				else
				{
					result = "Correct IP address";
				}
			}
			addressTmp.erase(0, 1);
			octet = "";
			break;
		}	
	}
	
	if (dots < 4)
	{
		octets(0);
	}
		
	return fine;
}

int main()
{
	input();
	if (afterZero == 0)
	{
		octets(0);
	}
	output();

}