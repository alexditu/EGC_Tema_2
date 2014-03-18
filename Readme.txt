EGC - Tema 2
	Crazy Driver
	Ditu Alexandru Mihai 333CA
	
Cuprins
1. Cerinta
2. Utilizare
3. Implementare
4. Testare
5. Probleme aparute
6. Continutul Arhivei
7. Functionalitati

1. Cerinta
	Utilizand frameworkul de la laborator trebuie sa implementam o varianta simplificata
a unui joc 3D de curse de masini auto cu obstacole.

2. Utilizare
	Tastele folosite sunt:
		- Sagetile UP, DOWN, LEFT, RIGHT pentru deplasarea masinii.
		  Cat timp tasta UP e apasata masina accelereaza pana la viteza maxima,
		  daca este eliberata, masina pierde treptat din viteza.
		  Daca este apasa tasta DOWN masina franeaza, pana la viteza zero.
		  LEFT si RIGHT muta masina stanga si dreapta.
		- Optional pot fi folosite tastele:
			- 'a' si 'z' pentru a modifica perspectiva pe axa OX.
			- 's' si 'x' pentru a modifica perspectiva pe axa OY.
			- 'd' si 'c' pentru a modifica perspectiva pe axa OZ.
			- 'q' si 'e' pentru a roti masina pe axa OY (aceste taste
			  nu au nicio relevanta practica, dar pot fi folosite
			  pentru a vedea cum arata masina)
			- de asemenea nu trebuie "abuzat" de tastele pentru modificarea
			  perspectivei, deoarece e posibil sa nu mai arate bine.
			
3. Implementare
	IDE:	Visual Studio 2012
	SO:		Windows 7 Professional, 64bit
	Framework-ul folosit este cel din lab3.
	Mentionez ca nu am testat tema pe niciun alt calculator.
	
	Pe langa clasele din framework am mai adaugat urmatoarele clase:
	- Collision.h/.cpp:
		- functie ce implementeaza mecanismul de coliziuni (acelasi ca la tema1)
		- coliziunile sunt de tipul segment - segment
	- GenericObject.h/.cpp
		- este clasa pe care toate obiectele mele (inamicii si masina) o deriveaza
		  si anume: Enemy1, Enemy2, Enemy3, Enemy4, Shield, PlayerCar.
		- contine informatii generice despre obiecte:
			- un vector cu elementele din care este alcatuit un obiect (de tipul
			  Object3D*)
			- pozitia, centrul, viteza, tipul etc.
			- cat si metode pentru a modifica diverse variabile
	- Enemy1.h/.cpp
		- creeaza un inamic ce arata ca un paralelipiped albastru
	- Enemy2.h/.cpp
		- creeaza un inamic ce arata ca o piramida
	- Eenemy3.h/.cpp
		- creeaza un inamic de tip Wheel (un cilindru cu baza octogon)
	- Enemy4.h/.cpp
		- creeaza un inamic ce arata ca un paralelipiped portocaliu
	- Shield.h/.cpp
		- creeaza un inamic ce arata ca un triunghi cu varful in jos
		  si baza avand colturile taiate
	- Paralelipiped.h/.cpp
		- creaza un paralelipiped
	- PlayerCar.h/.cpp
		- creeaza masina player-ului (de culoare rosie)
		- este alcatuita din 2 paralelipipede si 4 roti de tipul wheel (mai multe
		  explicatii despre roti, la clasa wheel) de culoare neagra
		- rotile masinii se rotesc in functie de viteza
	- Road.h/.cpp
		- creeaza drumul
		- acesta este alcatuit din:
			- drumul propriu-zis: un dreptunghi (care trebuia sa fie un obiect 3D, deci
			  am creeat un paralelipiped de inaltime 0)
			- pe drum am desenat si 2 benzi intermitente de culoare alba, dar
			  acestea fac parte din alta clasa
	- Strip.h/.cpp
		- creeaza cele 2 benzi intermitente
		- in main creez mai multe obiecte de tipul Strip, pe care le animez, pentru
		  a creea efectul de miscare.
		- benzile se tot shifteaza pe axa OZ spre +inf, pana cand ies de pe drum
		- in momentul in care au iesit de pe drum, le redesenez la inceputul acestuia
	- Wheel.h/.cpp
		- creeaza rotile
		- o roata e un cilindru cu baza octogon.
		- deorece am creeat cilindrul in picioare, acesta trebuie rotit cu 90
		  pe axa OZ ca sa semene mai mult cu o roata; in plus in momentul in care
		  se si invarte pe axa OX pare si ca este rotunda
4. Testare
	...
5. Probleme aparute
	...
6. Continutul arhivei
	- tot frameworkul de la laboratorul 3
	- Collision.h/.cpp
	- Enemy1.h/.cpp
	- Enemy2.h/.cpp
	- Enemy3.h/.cpp
	- Enemy4.h/.cpp
	- GenericObject.h/.cpp
	- Paralelipiped.h/.cpp
	- PlayerCar.h/.cpp
	- Road.h/.cpp
	- Shield.h/.cpp
	- Strip.h/.cpp
	- Wheel.h/.cpp
	- Readme
	
7. Functionalitati
	- Tema reprezinta un joc cu 3D cu o masina care merge pe un drum si se
	  fereste de obstacole.
	- In partea de sus a ecranului se afla informatiile despre jocul curent:
	  -Distanta, Scor, Vieti ramase, Timpul scurs de cand a inceput jocul
	- pe mijlocul ecranului se afla drumul (gri, cu benzi intermitente albe)
	- pe drum este masina (rosie cu roti negre)
	- masina nu se misca daca nu este apasata tasta UP
	- pe masura ce este apasata tasta UP lucrurile incep sa se miste:
	  - toate obiectele se deplaseaza in functie de viteza curenta a msinii
	    (mai putin inamicii de tipul 4, acestea au si viteza proproie, mai
		multe detalii la sectiunea "Tipuri de inamici")
	  - masina in realitate sta pe loc, iar obiectele vin spre masina
	  - cat timp tasta UP e apasata, viteza masinii creste pana la un topSpeed
	  - obiectele incep sa apara random la intervale regulate de timp (am o variabila
	    elipsedTime ce se incrementeaza in onIdle(), iar o data ce conditia
		elipsedTime >= 600/car.getSpeed() este indeplinita se mai afiseaza un inamic
		iar elipsedTime devine 0.
	  - toti inamicii sunt deja desenati din init(), numai ca sunt pusi in spatele 
	    masinii (deci nu se vad); a fost nevoie sa fac acest lucru pentru ca altfel
		nu s-ar fi vazut (daca ii adaugam dupa, acestia s-ar fi pus sub drum)
	  - daca masina se intersecteaza cu vreun inamic:
	    - player-ul pierde o viata
		- viteza masinii devine 0
		- scade scorul
		- inamicul este sters din teren (de fapt este mutat in spatele masinii)
		- coliziunea cu inamicii se face astfel:
		  - pentru fiecare obiect (ce extinde GenericObject) calculez (atunci cand
		    este creeat) punctele minime si maxime pe axa OX si OZ pentru a putea
			incadra fiecare obiect intr-un dreptunghi (in planul XOZ, ca o umbra a 
			obiectului). E suficient doar planul XOZ deoarece stiu sigur ca niciun
			obiectu nu se misca pe axa OY. Apoi, pentru fiecare obiect care este pe
			drum, verific daca vreo una din laturile dreptunghiului corespunzator
			masinii player-ului se intersecteaza cu vreo una din laturile corespunzatoare
			dreptunghiului fiecarui inamic ce se afla pe sosea.
	- daca tasta UP este eliberata, atunci masina pierde treptat din viteza pana
	  cand ajunge la 0.
	- daca tasta DOWN este apasata, atunci masina franeaza pana la viteza 0.
	- cu ajutorul sagetilor LEFT si RIGHT masina se poate feri de obstacole (mutandu-se
	  la stanga si la dreapta); masina nu are voie sa iasa de pe drum.
	- pe masura ce masina inainteaza, creste scorul jucatorului si scade distanta pana
	  la finish.
	- dupa ce parcurge toata distanta jocul se termina
	
	Tipuri de inamici:
	- am 4 tipuri de inamici si un alt corp pentru Bonus
	- inamicii sunt:
		- type 1 : un paralelipiped
		- type 2 : o piramida
		- type 3 : un cilindru cu baza octogon (acesta se si roteste pe masura ce vine 
		  spre player)
		- type 4 : un triunghi cu varful in jos si colturile de sus taiate (ar trebuie sa
					semene cu semnul lui superman 3D :).
					Acest inamic este pentru Bonus.
		- type 5 : inca un paralelipiped (portocaliu);
					acesta este un inamic mobil: viteza lui este 
					= viteza masinii - viteza proprie;
					in cazul in care viteza-masina < viteza-proproie inamicul se misca (pe
					axa OZ) spre -inf, deci se indeparteaza de player.
					O data ce iese de pe drum, obiectul este sters, nu poate aparea mai tarziu.
					Pe parcrusul jocului tot apar astfel de inamici
					
	Bonus:
		- pentru inamicul de tipul 4 (Shield.cpp) am implementat urm bonus:
		  atunci cand este atins de player acesta poate sa intre in ceilalti inamici
		  fara sa piarda din viteza sau puncte, in plus ii cresc punctele (functioneaza
		  ca un scut). Power-up dureaza 5 secunde iar timpul ramas apare si pe ecran
		  (ca sa stii cand expira sa nu te mai izbesti in inamici)
		- modele mai complexe pentru jucator:
			- acesta arata ca in imaginea din tema (in plus si rotile se invart)
		- "semnul lui superman" pt activare Bonus Shield
		- benzi intermitente animate pentru sosea
	
	
	
	
	
	
	
	
	
	
	