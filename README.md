# barbeiro_dorminhoco
 Este trabalho visa à implementação de um mecanismo de comunicação e sincronismo entre threads e gerenciamento da seção crítica.

 O trabalho consiste na implementação, em linguagem C++ com orientação a objetos, de um dos problemas clássicos de sincronismo.

A implementação poderá utilizar qualquer mecanismo de sincronismo desejado: semáforos, monitores, espera ociosa, etc., que se fizerem necessários. A compilação e correção será feita exclusivamente em Linux, portanto, recomenda-se que sejam utilizados recursos da API desse sistema operacional ou uma implementação portável para ele. As threads que representam o problema devem ser criadas utilizando, exclusivamente, a biblioteca thread da especificação de linguagem C++11 ou superior.

O problema a ser implementado é o problema do Barbeiro Dorminhoco. Este problema pode ser definido da seguinte forma:

A barbearia é composta por uma sala de espera com n cadeiras, mais a cadeira do barbeiro. Caso a barbearia esteja vazia (nenhum cliente esperando), o barbeiro se assenta na sua cadeira e dorme. Quando chega um cliente:

1.	Se todas as cadeiras estiverem ocupadas por clientes esperando, este novo cliente vai embora.
2.	Se o barbeiro estiver cortando o cabelo de um cliente na sua cadeira, mas houver vagas nas cadeiras de espera, este novo cliente se assenta em uma delas e aguarda sua vez.
3.	Se o barbeiro estiver dormindo, este cliente o acorda e corta o cabelo.

O objetivo do trabalho é implementar a thread Barbeiro e diversas threads Cliente, que se comportarão como descrito acima. O programa deve exibir mensagens que indiquem o que está acontecendo, como por exemplo (lista não exaustiva):

-	Não há clientes para atender, o Barbeiro foi dormir.
-	Chegou novo Cliente.
-	Não existem cadeiras de espera disponíveis, Cliente foi embora.
-	Existem x de y cadeiras livres para espera, Cliente aguardando sua vez. [Nota: x é o número de vagas e y é a quantidade de cadeiras determinada na implementação]
-	O Barbeiro está dormindo.
-	O Barbeiro está cortando o Cabelo do Cliente x. [Nota: x é o número da cadeira que o cliente estava ocupando na espera]
-	Não há clientes em espera, o Barbeiro foi dormir.
-	Cliente acordou o barbeiro.

O código deve evitar condições de disputa na seção crítica. Os tempos de chegada de cada cliente são aleatórios (utilize a biblioteca random de C++ e a chamada de sistema sleep para esperar um tempo aleatório).

Os clientes são representados por um número fixo de threads, que executam de forma contínua: chegam à barbearia, verificam se tem vaga, se tiver, ocupam um assento, se não, esperam um tempo aleatório para reiniciar o processo.

O programa executará indefinidamente. O encerramento ocorrerá quando o processo receber o sinal de término (SIGTERM) por teclado (ver tratamento de sinais em Linux). Quando encerrar, todos os recursos devem ser liberados e o programa deve exibir a mensagem: "Encerramos o expediente por hoje, volte amanhã!".

