#
# GCC vs. IAR Vergleich Tests

Autor: Scott Madeux

GitHub Repository: [smadeux/KATEK\_Compiler\_Vergleich (github.com)](https://github.com/smadeux/KATEK_Compiler_Vergleich)

# Einführung

Dieses Dokument enthält Information über die Tests, die ich gemacht habe, um die GCC und IAR Compiler zu vergleichen.

Die &quot; **Compiler Haupttests STM32H743ZI**&quot; und &quot; **ISR Vergleich**&quot; Ordner in der GitHub Repository enthält die STM32CubeIDE und IAR Embedded Workbench Testprojekt Dateien. Der Ordner &quot;Test Dateien&quot; enthält einigen Dateien die Tests zu erklären.

# Durchgeführte Tests

Bisher habe ich folgenden Tests durchgeführt:

1. 10x10 Matrix Dot-Produkt
2. Switch Case mit sequentiellen Cases und die Nummern 0-99 übergeben
3. Switch Case mit nicht-sequentiellen Cases und die Nummern 0-99 übergeben
4. Switch Case mit sequentiellen Cases und zufälligen Nummern übergeben
5. Switch Case mit nicht-sequentiellen Cases und zufälligen Nummern 0-99 übergeben
6. Dividieren ein zufällige Int durch ein über gegebene zufällige Int
7. Dividieren ein zufällige Float durch ein über gegebene zufällige Int
8. Sortieren ein zufälliges Array von 20 Ints mit dem Bubble Sort
9. Das Timing von ein leere Interrupt Service Routine (ISR)

# Testmethoden

Für alle die Tests außer dem ISR Test, habe ich die Testfunktionen innerhalb einer Datei namens &quot;testfunktionen.c&quot; und Aufrufe für diesen Funktionen innerhalb die while Schleife in die main Funktion. Für jede Test habe ich nur unkommentiert die Funktionsaufrufe, die ich für diesen bestimmten Test brauchte. Alle anderen Funktionsaufrufe blieb auskommentiert.

Ich habe jede Funktion, außer dem ISR Test, 100-mal ausgeführt und die Geschwindigkeit davon gemessen mit einem Oszilloskop, der zu der PC6 Pin verbindet war. Der PC6 Pin wird umgeschaltet vor und nach der For Schleife, die der Funktionsaufruf enthält. Ich habe einfach der Distanz gemessen zwischen wann das Signal aus dem PC6 Pin hoch gegangen hat und wann es nochmal tief geworden war.

Für der ISR Test habe ich ein paar Zeilen von code in einigen Dateien eingefügt (sehen Sie die GitHub Repository **Test Dateien/ISR Test** ). In der Datei &quot;stm32h7x\_hal\_tim.c&quot; auf Zeile 3876 liegt der Funktionsaufruf für die ISR. Ich habe ein Umschalten Befehl vor und nach diesem Funktionsaufruf gestellt. Ich habe auch zur Datei &quot;stm32h7x\_hal\_tim.h&quot; ein #define Anweisungen für den GPIO Pin hinzugefügt und ein paar andere Zeile in &quot;main.c&quot;.

Für jeden Test und Compiler waren die Größe des RAMs und des Flashes und die Geschwindigkeit des Programms gemessen. Diesen Daten war benutzt der Unterschied zwischen beide Compiler zu rechnen.

Jede Funktion war ausgeführt mit drei unterschiedlichen Optimization Einstellungen und die Geschwindigkeit und Größe von jeder waren vergleichen.

1. Low (IAR) / -O0 (GCC)
2. High(Size) (IAR) / -Os (GCC)
3. High(Speed) (IAR) / -Ofast (GCC)

# Ergebnisse

Man kann die Ergebnisse die Tests an diesen Link sehen: [Compiler Vergleich Tests](https://docs.google.com/spreadsheets/d/1RVlDTV-CwyqjvsGuWr_7Q_aEwlhB48mcp6GdHHg2v9w/edit?usp=sharing)

**Hinweis:** Rot bedeutet der IAR Compiler schneller ist oder großer Code erstellt und grün bedeutet der GCC schneller ist oder großer Code erstellt.

# Testwiederholung

Folgen Sie dieser Link ([smadeux/KATEK\_Compiler\_Vergleich (github.com)](https://github.com/smadeux/KATEK_Compiler_Vergleich)) und die Repository herunterladen.

**Tests 1-8:**

1. Innerhalb die &quot; **Compiler Haupttests STM32H743ZI**&quot; Ordner findet man eine STM32CubeIDE Datei namens &quot; **.project**&quot; und eine IAR Embedded Workbench Datei unter der Ordner EWARM namens &quot; **Project.eww**&quot;.
2. Öffnen Sie diesen beiden Projekten und dann können Sie jetzt alles innerhalb der STM32CubeIDE oder der IAR Embedded Workbench ausführen und die Platte durch den **PC6 Pin** zu einem Oszilloskop verbinden.

**ISR Test:**

1. Öffnen Sie Ordner namens &quot;ISR Vergleich&quot; und der Rest ist gleich als den anderen Tests.

**Hinweis:** Bitte klicken Sie nicht &quot;Generate Code&quot; für das ISR Test Projekt als wichtigen Teilen des Tests gelöscht werden.