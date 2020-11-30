<h2 align="center"><center>Sprawozdanie</center>
<br>Programowanie równoległe i rozproszone</h2>
Pracę nad programami zacząłem od włączenia linuxa na virtualboxie, następnie zainstalowania MPI.

```md
sudo apt install libopenmpi-dev
```

Po zainstalowaniu biblioteki zacząłem pisać kod <b>zad1.c</b>
```md
mpicc zad1.c -o zad1.exe -lm
mpirun -np 3 zad1.exe
```
Otrzymałem:
```md
Wartosc PI= 3.1412671327650821, Blad= 0.0003255208247110
Czas programu: = 0.000127
```

<b>zad2.c</b>
```md
mpicc zad2.c -o zad2.exe -lm
mpirun -np 4 zad1.exe
```

```md
PID = 3
suma = 10.000000

PID = 2
suma = 2.000000

PID = 1
suma = 28.000000

PID = 0
SUMA = 32.000000
```
Legenda najważniejszych funkcji:<br>
MPI_Init - Funkcja inicjalizuje środowisko wykonywania programu. Dopiero od momentu wywołania MPI_Init można używać pozostałych funkcji MPI<br>
MPI_Finalize - Funkcja zwalnia zasoby używane przez MPI i przygotowuje system do zamknięcia.<br>
MPI_Reduce - Bardzo ważna funkcja - pozwala wykonać na przykład sumowanie wszystkich częściowych wyników otrzymanych w procesach i umieszczenie wyniku w zmiennej.<br>
MPI_Bcast - Funkcja rozsyła komunikat do wszystkich procesów w obrębie komunikatora MPI_COMM<br>
MPI_Comm_rank - Funkcja pobiera numer aktualnego procesu (w obrębie komunikatora MPI_COMM) i umieszcza go w zmiennej.<br>
MPI_Comm_size - Funkcja pobiera ilość procesów (w obrębie komunikatora MPI_COMM i umieszcza ją w zmiennej.<br>
