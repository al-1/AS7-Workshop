> This Workshop was held in German and also the Script is in German so this read me will be also in German

###Workshop: Arduino Uno, Atmel Studio 7.0 und C 
####Workshop Material
In diesem Repostitory befinden sich zwei pdf-Dateien einmal die Version wie sie auch in gedruckter Form vorlag und einmal korrigiert/erweitert.  
Des weiteren findet sich der Kurzvortrag über den Workshop ebenfalls hier.
####Wie bekomme ich Atmel Studio?
[Hier](https://www.mikrocontroller.net/articles/Atmel_Studio#Direktlinks_Installer) gibt es eine Auflistung von links zum Download. 
####Errata zur ersten Version
Die gedruckte erste Version vom Script hat folgende Bekannte Fehler: diese Fehler sind in der korrigierten zweiten Version behoben. 

 * Auf Seite 2 steht ein nicht korrekter String für das Argument von AVEdude. Im Script steht: `Argument: -CV:\workshop\avrdude.conf -patmega328p -carduino -P\\.\COM14 -b57600 -Uflash:w:"$(ProjectDir)Debug\$(ItemFileName).hex":i`  
  Dieses Argument ist allerdings das richtige, verwendet man den Arduino Uno.  Für den Arduino Uno ist folgendes Argument richtig:  
  `-CV:\workshop\avrdude.conf -patmega328p -carduino -P\\.\COM14 -b115200 -Uflash:w:"$(ProjectDir)Debug\$(ItemFileName).hex":i`
 * Seite 6 Tabelle unten mit Bitweise Operationen das Beispiel für bitweise UND ist total falsch. So wies da steht wäre das Ergebnis gleich null.
 * Seite 7  Es Fehlt eine Semikolon bei:  
   `DDRD|=(1<<3);`
 * Seite 14 Kapitel 2.7: Hier passt der Text nicht mit dem Code zusammen mit Text wird eine **fallende** Flanke beschrieben. Im code Beispiele wird aber auf eine steigende Flanke, also auf ein wieder loslassen des Taster, abgefragt. 

####Ideen für weitere Kpitel
 * Analoge Eingänge einlesen / ADC
 * Frequenz variables Rechtecksignal mit OCR und compare match Interrupt erzeugen