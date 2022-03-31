Help:<br />
 -h help<br />
 -r wczytaj graf z pliku tekstowego o nazwie mojGraf.txt<br />
 -g generoj graf: podaj ilosc wierczy i kolumn oraz podaj przedzial wag krawedzi grafu<br /><br />
	Fromat danych:<br />
	W pierwszej linijce pliku powinny znalezc sie dwie liczby naturalne(liczba wierszy i kolumn).<br />
	Nastepnie w formacie listy powinny znalezc sie wierzcholki docelowe oraz waga krawedzi,<br />
	gdzie wierzcholkiem zrodlem jest index linii -2.<br />
	Na koncu pliku powinien znalezc sie eneter.<br />

Przykladowy plik:<br />

	2 3
		1 :0.2  3 :0.3
		0 :0.1  2 :0.8  4 :0.5
		1 :0.7  5 :0.9
		0 :0.6  4 :0.4
		3 :0.3  1 :0.9  5 :0.7
		2 :0.8  4 :0.9

W tym przypadku powstanie graf 2x3, gdzie wierzcholek 0 zostanie polaczony z<br />
wierzcholkiem 1 waga 0,2, oraz z wierzcholkiem 3 waga 0,3 itd.<br />
Przykladowe wywolanie: ./GraphAnalizer -g 3 8 4.2 7.3<br />
Wygenerowany zostanie graf o wielkosci 3x8 z krawedziami w zakresie <4,2 ; 7.3><br />
