#include "BSL.h"
#include <iostream>

using namespace std;
using namespace SVG;

int main() 
{
	short bck, font;
	setcolor(6);
	cout << "\n\n\n\n\n\t  :::::::::   ::::::::  :::             :::            :::     ::::    :::  ::::::::  :::    :::     :::      ::::::::  :::::::::: ";
	cout << "\n\t  :+:    :+: :+:    :+: :+:             :+:          :+: :+:   :+:+:   :+: :+:    :+: :+:    :+:   :+: :+:   :+:    :+: :+:        ";
	cout << "\n\t  +:+    +:+ +:+        +:+             +:+         +:+   +:+  :+:+:+  +:+ +:+        +:+    +:+  +:+   +:+  +:+        +:+        ";
	cout << "\n\t  +#++:++#+  +#++:++#++ +#+             +#+        +#++:++#++: +#+ +:+ +#+ :#:        +#+    +:+ +#++:++#++: :#:        +#++:++#   ";
	cout << "\n\t  +#+    +#+        +#+ +#+             +#+        +#+     +#+ +#+  +#+#+# +#+   +#+# +#+    +#+ +#+     +#+ +#+   +#+# +#+        ";
	cout << "\n\t  #+#    #+# #+#    #+# #+#             #+#        #+#     #+# #+#   #+#+# #+#    #+# #+#    #+# #+#     #+# #+#    #+# #+#        ";
	cout << "\n\t  #########   ########  ##########      ########## ###     ### ###    ####  ########   ########  ###     ###  ########  ########## ";
	setcolor(15);
	cout << "\n\n\n\n\n\t\tyou can change color in program with \"option\" command\n\t\tchoose font color\n\t\t\t\t";
	for (int i = 0; i < 16; i++)
	{
		setcolor(i);
		cout << i<<" ";
	}
	cout << "  : ";
	cin >> font;
	cout << "\n\n\t\tchoose background color\n\t\t\t\t";
	for (int i = 0; i < 16; i++)
	{
		setcolor((i*16)+font);
		cout << i << " ";
	}
	setcolor(15);
	cout << "  : ";
	cin >> bck;
	cin.ignore(INT_MAX, '\n');
	BSL * Program = new BSL(bck, font);
	Program->start();
	return 0;
}