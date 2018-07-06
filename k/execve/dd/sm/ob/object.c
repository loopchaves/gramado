/*
 * File: sm\ob\object.c
 *
 * Descri��o:
 *   #importante: 
 *   O gerente de arquivos ser� o manipulador de arquivos usados pelo sistema 
 * de arquivos. Lembrando que o assim como no UNIX tudo � considerado um 
 * arquivo, aqui, tudo � considerado um objeto. Ent�o o sistema de arquivos 
 * manipular� os objetos. Mas ele poder� chama-los de arquivos se quiser. 
 *
 *    Object manager, m�dulo do tipo MB - M�dulos inclu�dos no Kernel Base.
 *
 * Arquivo principal do m�dulo sm\ob do executive.
 *    
 * Gerencia os recursos do sistema. Criando, abrindo, fechando objetos e 
 * concedendo ou negando o acesso a ele.
 *
 *    Para gerenciar o uso de um recurso o kernel faz utiliza semaforos, 
 * mutexes.
 * 
 * Ex: Um fs � um objeto, que tem seu channel pra receber mensagens e uma 
 * aplica��o solicita alguma coisa do sistema de arquivos atrav�s de um 
 * canal de comunica��o. O fs pode estar indispon�vel no momento. 
 * A aplica��o cliente pode ser um cliente n�o valido.
 *
 * Obs: 
 * O object manager � o melhor lugar pra implantar rotinas de seguran�a.
 *
 * Claro que o Object Manager deve chamar as rotinas do m�dulo de seguran�a, 
 * mas o Object Manager receber� solicita��es de usu�rios e processos para 
 * manipular objetos, ent�o deve decidir se o usu�rio, grupo ou processo 
 * tem autoriza��o para manipular o objeto.
 *
 * Obs: 
 * Uma estrutura de objeto deve conter indica��es de que processo ou usu�rio 
 * est� manipulando o objeto no momento. Tamb�m um n�mero m�ximo de processos 
 * que pode ficar na fila para usar esse objeto. A fila decrementa e quando 
 * chegar a zero, esse objeto pode ser fechado, caso n�o seja um objeto f�sico, 
 * como no caso de discos.
 *
 *IMPORTANTE: 
 * Que ningu�m duvide da import�ncia do gerente de objetos. Pois os recursos 
 * do sistema s�o configurados como objetos, ent�o para um processo ter acesso 
 * � algum recurso do sistema ter� que solicitar o recurso ao gerente de objetos, 
 * que pode interagir com o sistema de seguran�a para ver se o processo ou 
 * usu�rio tem permiss�o para utilizar o recurso desejado. 
 *
 * @todo: 
 * Ainda h� muito pra aprender sobre objetos e gerencia de objetos. 
 * Tendo em vista que o conceito de objetos para kernel mode em C e para 
 * User Mode com linguagem de alto n�vel � bem diferente.
 *
 * Vers�o: 1.0, 2015 - Esse arquivo foi criado por Fred Nora.
 * Vers�o: 1.0, 2018 - ?
 */
 
 
#include <kernel.h>

//Vari�veis internas.
//int objectmanagerStatus;
//



/*
 * init_object_manager:
 *     Inicializa o gerenciador de objetos.
 *
 */
int init_object_manager()
{
    int Status = 0;
	
	printf("Initializing Object Manager ...\n");
    
	g_current_object = 0;         //objeto numero 0
    g_current_list = OBJECTS_KM;  //lista de objetos em kernel mode.
	
	//test
	//@todo: N�o usar array de estrutura.
	// Usar um array simples tipo Objects[];
	//Onde ficar�o armazenas os ponteiros para as estruturas.
    
	//objects_km[0].id = 0;    
    //objects_km[0].used = 1;    
    //objects_km[0].magic = 1234;    
	//...
	
	
	//@todo: initialize object List.
	
//Done.	
done:
    //Inicializado.
	g_object_manager_status = 1;
	g_module_objectmanager_initialized = 1;
	printf("Done!\n");
    return (int) Status;
};



//
//void *objectCreate(...)
//int objectOpen(...)
//int objectClose(...)


/*
int objectmanagerInit()
{
    return (int) init_object_manager();	
};
*/

//
// Fim.
//

