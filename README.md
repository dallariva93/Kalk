# Kalk
Progetto di programmazione ad oggetti a.a. 2017/2018

Idee:
* La calcolatrice deve operare tra poligoni(un certo numero e tipo) e colori.
* Le classi derivate da poligono potrebbero essere triangolo, quadrilatero e pentagono(ognuna delle quali può avere un calcolo specifico dell'area, perimetro, etc.. in base al fatto se è un poligono equilatero, equiangolo, regolare, etc.. ) 
* Nella GUI do la possibilità di creare oggetti e di operare selezionandoli da una lista

**Colori:**
* I colori dovrebbero essere basati sul sistema esadecimeale e costruiti tramite il modello RGB e/o CMYK (o altri modelli)

**Poligoni:**
* I poligoni possono essere costruti tramite punti, segmenti e angoli, sarebbe interessante avere dei costruttori adeguati con i tre tipi di dato, che però andranno implementati
* costruire solamente dati punti o segmenti è possibile, mentre solamente tramite angoli no, serve minimo un lato.
* Ci sarà una classe base astratta "Poligono", con alcuni metodi virtuali puri (getArea, getPerimetro ecc). 
* Campi dati del poligono sono colore, lato e angolo, che verranno ereditati nelle altre classi e con adeguati valori di default.

**Operatori:**
* Ci dovrebbero essere operazioni tra colori e colori, poligoni e colori, poligoni e poligoni.
* Quest'ultimo tipo potrebbe essere complicato (es: somma/sottrazione tra 2 poligoni sarebbe l'unione dei due...sommando due triangoli ottengo un quadrilatero, sommando due quadrilateri posso ottenere un altro quadrilatero oppure un pentagono in base ai casi, sommando due pentagoni..diventa un pò problematico ) 
* Per la divisione potremmo fare che si riduce il poligono, ad esempio diviso due si dimezza la dimensione quindi cambia la lunghezza dei lati e il valore del perimetro e area ma la misura degli angoli è invariata, lo stesso per la moltiplicazine solo che aumenta la grandezza del poligono.
* Per i poligoni ci saranno operatori unari per la maggior parte
* Per i colori ci saranno le operazioni principali che agiranno sui valori rgb (somma sottrazione moltiplicazione e divisione su r, g, b.
