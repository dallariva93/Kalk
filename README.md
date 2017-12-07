# Kalk
Progetto di programmazione ad oggetti a.a. 2017/2018

Idee:
* La calcolatrice deve operare tra poligoni(un certo numero e tipo) e colori
* Nella GUI do la possibilità di creare oggetti e di operare selezionandoli da una lista

**Colori:**
* I colori dovrebbero essere basati sul sistema esadecimeale e costruiti tramite il modello RGB e/o CMYK (o altri modelli)

**Poligoni:**
* I poligoni possono essere costruti tramite punti, segmenti (che sono 2 punti)e angoli, sarebbe interessante avere dei costruttori adeguati con i tre tipi di dato, che però andranno implementati
* Ci sarà una classe base astratta "Poligono", con alcuni metodi virtuali puri (getArea, getPerimetro ecc)

**Operatori:**
* Ci dovrebbero essere operazioni tra colori e colori, tra poligoni e colori e poligoni e poligoni, quest'ultimo tipo potrebbe essere complicato (es: somma tra 2 poligoni sarebbe l'unione dei due
* Per i poligoni ci saranno operatori unari per la maggior parte
* Per i colori ci saranno le operazioni principali che agiranno sui valori rgb (somma sottrazione moltiplicazione e divisione su r, g, b.
* 
