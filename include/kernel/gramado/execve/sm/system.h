/*
 * File: sm/system.h (System Management)
 *
 * Descri��o:
 *     Header para rotinas de gerenciamento do sistema dentro do m�dulo 
 * executive do kernel.
 *     O subsistema recebe as chamadas dos programas que est�o em use mode. 
 * � a porta de entrada para o kernel.
 *
 * Obs:
 *     Lembrando que o sistema compreende o Boot, Kernel e User.
 *
 * @todo:
 *     todos os servi�os oferecidos est�o nos 
 *     arquivos principais dos m�dulos hal microkernel e executive
 *     e come�am com 'sys_'.
 *
 * Hist�rico:
 *     Vers�o 1.0, 2015 - Esse arquivo foi criado por Fred Nora.
 *     Vers�o 1.0, 2016 - Aprimoramento geral das rotinas b�sicas.
 *     //...
 */





void servicesPutChar ( int c );
void servicesChangeProcedure();
unsigned long serviceCreateWindow ( char * message_buffer );


//
// ## sys storage support ##
//
 
int system_disk;
int system_volume; 

 
//======================================== 
//Esses s�o os principais arquivos usandos na 
//inicializa��o do sistema. 
//Obs: No fat16 eles se apresentam em mai�sculas.
//#define INITTXT_PATH  "/root/init.txt"
//#define BM_PATH       "/root/bm.bin"
//#define BL_PATH       "/root/bl.bin"
//#define KERNEL_PATH   "/root/kernel.bin"
//#define INIT_PATH     "/root/init.bin"
//#define SHELL_PATH    "/root/shell.bin"
//#define TASKMAN_PATH  "/root/taskman.bin" 
//...
//========================================
 

#define SYSTEMMODE_EDITBOX  0
#define SYSTEMMODE_TERMINAL 1
int g_system_mode;  //terminal ou edibox. 



//
// Identifica��o do processo que est� efetuando logon e 
// identifica��o do processo que est� efetuando logoff.
// Precisamos registrar o processo que efetuou logon.
// ?? Porque eu ainda n�o sei.
// Uma rotina de registro de processo de logon 
// ser� oferecida para processos em user mode,
// � necessario enviar uma flag de seguran�a,
// pode ser um magic number ...
// ent�o esse proecesso ter� direito de efetuar o logon 
// se tiver privil�gios v�lidos em sua estrutura.
// logo em seguida registraremos qual foi o processo 
// que efetuou logon. Outro processo n�o poder� 
// efetuar logon durante aquela sess�o.
// Caso semelhante � o logoff. O processo dever� 
// enviar uma flag de seguran�a e ter atributos v�lidos 
// para efetuar o logoff.
//
//

int gLogonPID;
int gLogoffPID;
 
 
int systemGetTerminalWindow(); 
 
//configuramos a janela do terminal virtual corrente.. 
//@todo: isso deve ser uma op��o de system call. 
void systemSetTerminalWindow( struct window_d *window );


//configuramos o ret�ngulo do terminal virtual corrente.. 
void systemSetTerminalRectangle( unsigned long left,
                                 unsigned long top,
								 unsigned long width,
								 unsigned long height );









/*
 * Abaixo temos uma lista de variaveis de ambiente usadas
 * pelo sistema, come�adas com SYSTEM_.
 *
 */ 


/*
 * Disks
 *    Discos f�sicos   
 */
#define SYSTEM_DISK0  "/disk0" 
#define SYSTEM_DISK1  "/disk1"
#define SYSTEM_DISK2  "/disk2"
#define SYSTEM_DISK3  "/disk3"
#define SYSTEM_DISK SYSTEM_DISK0  
//...

/*
 * Volumes
 *    Cada parti��o � um volume.
 *    Um volume pode ocupar mais de um disco. 
 */
#define SYSTEM_VOLUME0  "/volume0"   //vfs
#define SYSTEM_VOLUME1  "/volume1"   //parti��o de boot
#define SYSTEM_VOLUME2  "/volume2"   //parti��o do sistema.
#define SYSTEM_VOLUME3  "/volume3"   //??indefinido.

#define VHS_VOLUME    SYSTEM_VOLUME0
#define BOOT_VOLUME   SYSTEM_VOLUME1
#define SYSTEM_VOLUME SYSTEM_VOLUME2  
//...


#define SYSTEM_ROOT      "root:/"
#define SYSTEM_ROOTDIR   SYSTEM_ROOT      

 
/*
 * /disk0
 *     Esse ser� sempre o disco principal.
 *     Lista de diret�rios dentro do disco principal.
 */
 
//
// Obs: Isso s�o op��es ainda n�o definidas.
// 
 
//principais.  
#define SYSTEM_GUSERS    "/user"    // (os perfis de usu�rio ficar�o aqui.)
#define SYSTEM_GCMD      "/cmd"      //COMANDO USADOS PELO SHELL CHAMAR�O OS PROGRAMAS QUE EST�O AQUI.
#define SYSTEM_GTMP      "/tmp"      //ARQUIVOS TEMPOR�RIOS
#define SYSTEM_GDOWNLOAD "/download"  //DOWNLOADS

//secund�rios.
#define SYSTEM_GBUILD    "/gbuild"   //Build
#define SYSTEM_GDOCS     "/gdocs"    //Docs
#define SYSTEM_GRAMADO   "/gramado"  //System (aqui ficar�o os bin�rios dos programas, em pastas)
#define SYSTEM_GSDK      "/gsdk"     //SDK 
#define SYSTEM_GSRC      "/gsrc"     //Source 


//...

//files (path para alguns arquivos principais)
#define SYSTEM_BM       "/BM.BIN"
#define SYSTEM_BL       "/BL.BIN"
#define SYSTEM_KERNEL   "/KERNEL.BIN"
#define SYSTEM_IDLE     "/IDLE.BIN"
#define SYSTEM_TASKMAN  "/TASKMAN.BIN"
#define SYSTEM_SHELL    "/SHELL.BIN"
#define SYSTEM_INIT     "/INIT.TXT"   // CONFIGURA��ES DE INICIALIZA��O.
#define SYSTEM_SWAP     "/SWAP.BIN"   // (ARQUIVO DE PAGINA��O)
//...

 
//Computer.
#define SYSTEM_COMPUTER    "COMPUTER=$"

//Hadware.
//...

//User.
#define SYSTEM_USER        "USER=/$"
#define SYSTEM_USERNAME    "USERNAME="
//...

//Media.
#define SYSTEM_MEDIADISK    "MEDIA=/disk(0000)"
#define SYSTEM_MEDIAVOLUME  "MEDIA=/volume(0000)"    //Parti��o.
//...
 
//

//devices.
#define SYSTEM_DEVICE          "DEVICE=/$"
#define SYSTEM_DEVICECPU       "DEVICE=/cpu"
#define SYSTEM_DEVICEMEMORY    "DEVICE=/memory"
#define SYSTEM_DEVICENIC       "DEVICE=/nic"     //NIC (placa de rede).
#define SYSTEM_DEVICEKEYBOARD  "DEVICE=/keyboard"
#define SYSTEM_DEVICEMOUSE     "DEVICE=/mouse"
//...


//
// @todo: Continuar criando vari�veis de ambiente.
//

//...



//
//    ****    SYSTEM METRICS INDEX **** 
//


//*Importante.
#define SM_NULL 0  
#define SM_SCREENWIDTH 1
#define SM_SCREENHEIGHT 2
#define SM_BPP          3 //Bits Per Pixel.
#define SM_BACKBUFFER_VA 4  //Virtual address for backbuffer.
#define SM_BACKBUFFER_PA 5  //phisical address for backbuffer.
#define SM_FRONTBUFFER_VA 6  //Virtual address for frontbuffer.
#define SM_FRONTBUFFER_PA 7  //phisical address for frontbuffer.
#define SM_KERNELSIZE 8
#define SM_KERNELHEAPSIZE 9
#define SM_KERNELSTACKSIZE 10
#define SM_CHARWIDTH 11
#define SM_CHARHEIGHT 12
#define SM_DEVELOPER_EDITION 13

//Continua ...
//@todo.


//
//    ****    SYSTEM STATUS INDEX   **** 
//
//*Importante.
#define SS_NULL 0  
#define SS_LOGGED 1      //estamos logados.?
#define SS_USING_GUI  2  // estamos no modo gr�fico?
#define SS_KERNELSTATUS 3 //
//Continua ...
//@todo.

//procedure tupe mode
//@TODO: CRIAR UM ENUM
#define PROCEDURE_TYPE_MODE_TERMINAL  1    //digitando em um terminal/
#define PROCEDURE_TYPE_MODE_EDITBOX   2    //digitando em um editbox.
//...
 
//
// Globals.
// 

typedef enum {
    systemsizeNull,
    systemsize1,     //#  1 O sistema tem pelo menos 32 MB
    systemsize2,     //#E 2 O sistema tem pelo menos 64 MB
    systemsize3,     //#F 3 O sistema tem pelo menos 96 MB
    systemsize4,     //#G 4 O sistema tem pelo menos 128 MB 
    systemsize5,     //#A 5 O sistema tem pelo menos 160 MB 
    systemsize6,     //#B 6 O sistema tem pelo menos 192 MB 	
    systemsize7,     //#C 7 O sistema tem pelo menos 224 MB
    systemsize8,     //#D 8 O sistema tem pelo menos 256 MB
    systemsizeFull,  //     O sistema tem pelo menos 288 MB	
}system_size_t;


//?? rever esse coment�rio.
// Aqui salvaremos o n�mero que identifica o tipo de sistema dado o tamanho.
// Se o sistema tiver 288 MB ou mais ent�o ele ser� do tipo Full
// e conter� 8 bancos de mem�ria de 32Mb mais uma user session de tamnaho variado.
int systemSize;


//Flag para habilitar as op��es para o desenvolvedor.
int gDeveloperOptions;

//Sobre a destina��o do sistema operacional.
// 1 - Developer Edition.
// 2 - Workstation Edition.
// 3 - Server Edition.
// 4 - IOT Edition.
//...
int gSystemEdition;


int gSystemStatus; //?? Usado pelo construtor.


//
//  **** Shutdown support   ****
//

//Salvar aqui o endere�o da rotina do BM que desliga a m�quina via APM.
//O endere�o e a rotina s�o de 32bit.
unsigned long shutdown_address;

static char *default_user_name = "default-[USER]";
static char *systemDefaultUserName = "default-[USER]";
//...



//...


/*
 * Test.
typedef struct active_environment_d active_environment_t;
struct active_environment_d
{
	unsigned long disk_number;
	unsigned long volume_number;
    unsigned long directory_number;

    const char* disk_string;
    const char* volume_string;
    const char* directory_string;	
} 
struct active_environment_d *CurrentEnvironment;
*/ 


/*
 * VERSION:
 *     Estrutura para vers�o do sistema.    
 *     O que determina a vers�o do sistema � a vers�o do Kernel.
 *
 * @todo: 
 *     Usar apenas esses 4 elementos.
 *     Dados complementares sobre a vers�o devem ficar 
 *     na estrutura versioninfo.
 *
 * Obs: Talvez usar um header. version.h.
 * #bugbug j� tem version_t tefinida em algum lugar.
 *         Aparentemente n�o deu mais problema. 
 */
typedef struct version_d version_t;
struct version_d
{
    unsigned long Major;
    unsigned long Minor;	
	unsigned long Revision;
};
struct version_d *Version;
//...


/*
 * Version Info:
 *     Dados complemetares sobre a vers�o.
 */
typedef struct version_info_d version_info_t;
struct version_info_d
{
    struct version_d *version;    	
	char *string;             //String para o nome da vers�o "VERSION..."
	//char *string2;
	char *copyright_string;   //"ex: (c) Copyright Nora Code"
	//...
	
	//@todo:
	//Data,
	//
	
	//...
	
};
struct version_info_d *VersionInfo;

 

/*
 * system_d:
 *     System information structure:
 *     Essa estrutura guarda as informa��es gerais sobre o sistema.
 *     Guarda ponteiros para as principais estruturas do sistema, 
 * desde informa��es de boot, at� informa��es se��es de usu�rios.
 * 
 */

struct system_d
{
	int used;
	int magic;
	
	//version
	struct version_d *version;
	struct version_info_d *version_info;
	
	
	//
	// ## storage ##
	//
	
	int disk;
	int volume;
	
    //
    // System  info.
    //	
	int ProcessorArchitecture;
	int NumberOfProcessors;
	int PageSize;
	
	struct devices_d *deviceList;	
	
	
	//...
};
struct system_d *System;



//
// Prototypes.
//

		
/*
 * ldisc_dialog:
 *     Procedimento de dialogo usado para a manipula��o de 
 * eventos de teclado.
 *     esse procedimento deve ser chamado quando o sistema 
 * ou algum processo deseja interagir com o driver de teclado 
 *  ?? planejando a funcionalidade desse di�logo ??
 */
 
unsigned long 
ldisc_dialog ( struct window_d *window, 
               int msg, 
			   unsigned long long1, 
			   unsigned long long2 ); 
			   
							
/*
 procedimento de janleas do terminal.
*/
				
unsigned long 
terminal_dialog ( struct window_d *window, 
                  int msg, 
				  unsigned long long1, 
				  unsigned long long2 ); 

								
/*
 * system_procedure:
 *     O procedimento default do sistema.
 *     Obs: Essa rotina est� em procedure.c.  
 */			
 
unsigned long 
system_procedure ( struct window_d *window, 
                   int msg, 
				   unsigned long long1, 
				   unsigned long long2 );

													  
/*
 * systemcall:
 *     @todo: Essa fun��o deve ser chamada via kernel request quando em kernel mode.
 * Obs:
 *     As chamadas ao sistema s�o feitas via interrup��o, ou via kernel request.
 *     ??? @todo: Onde est� essa rotina ???
 */
 
int 
systemcall ( unsigned long number, 
             unsigned long ax, 
			 unsigned long bx, 
			 unsigned long cx, 
			 unsigned long dx ); 


/*
 * registra_procedimento:
 *     Registra um procedimento de janela.
 *
 */			
 
unsigned long 
registra_procedimento ( unsigned long arg1, 
                        unsigned long arg2, 
						unsigned long arg3, 
						unsigned long arg4 );
									 
/*
 * SendMessage:
 *     Envia mensagem para um procedimento de janela.
 */	
 
unsigned long 
SendMessage ( struct window_d *window, 
              int msg, 
			  unsigned long long1, 
			  unsigned long long2 );


/*
 * procedureHelp:
 *     Help messages.
 *     Obs: Essa rotina est� em procedure.c
 */
void procedureHelp ();


/*
 * systemAbort:
 *     Abort system.
 */
void systemAbort ();


/*
 * SetProcedure:
 *     Atualiza o procedimento atual.
 */
void SetProcedure(unsigned long proc);


// System Server support.
int init_systemserver ();


//Metodo nulo.
//Pode ser usado em di�logos.
void *systemNull ();  

	
/*
 *******************************************************
 * systemLinkDriver:
 *     Linkando um driver ao sistema operacional
 */
 
void *systemLinkDriver ( unsigned long arg1, 
                         unsigned long arg2, 
						 unsigned long arg3 );
						 
						 
/*
 **********************************************************
 * systemShowDevicesInfo:
 *     Mostrar informa��es sobre o sistema, seguindo a ordem de
 *     velocidade dos dispositivos e barramentos.
 *     Ex: CPU, Mem�ria, PCIE (video), South Bridge, Super Io ...
 *     Apresentar em ordem alfab�tica.
 */
 
void systemShowDevicesInfo ();
 
 
//Cria a barra de menu do sistema. 
void *systemCreateSystemMenuBar ();  



/*
 * systemCheck3TierArchitecture:
 *     ?? Checa as servi�os oferecids nas 3 camadas.
 */
//void systemCheck3TierArchitecture();


void systemSetupVersion(); 

/*
 * system_dispatch_to_procedure:
 *     Despacha uma mensagem para o procedimento de janela do sistema.
 *     Obs: Esse procedimento fica no kernel base em procedure.c
 */
int system_dispatch_to_procedure( struct window_d *window, 
                                int msg, 
								unsigned long long1, 
								unsigned long long2);
/*
 * SystemMenu: System Menu para manipular a janela ativa.
 * Interface que chama o control menu da janlea ativa.
 */
int SystemMenu();

 
//isso ser� um servi�o dispon�vel para a api, 
unsigned long systemGetSystemMetrics( int index );
 

/*
 * SystemMenuProcedure:
 *     O procedimento do Control Menu principal.
 *     Menu do sistema, manipula a janela ativa.
 */																
unsigned long SystemMenuProcedure( struct window_d *window, 
                                   int msg, 
								   unsigned long long1, 
								   unsigned long long2);
								   
void systemReboot();	    //systemReboot: Reboot stuff.						   
void systemShutdown();      //systemShutdown: Shut down stuff.
//Chamar a fun��o de 32 bit herdado do BM.
void systemShutdownViaAPM(); 
//Pega informa��es de medida de elementos do sistema.
void *systemGetSystemMetric(int number);
//Pega informa��es de status de elementos do systema.
void *systemGetSystemStatus(int number);


// ## Initializing ##
int systemStartUp();   // Inicializa��o do sistema.
int systemInit();      // Inicializador.
void systemSystem();   // Construtor.


// #importante
// Algumas fun��es chamadas por gde_services(...)
// Outras est�o em outros arquivos.


#define sys_my_read_hd_sector     my_read_hd_sector
#define sys_my_write_hd_sector    my_write_hd_sector 
#define sys_fsSaveFile            fsSaveFile
#define sys_backbuffer_putpixel   backbuffer_putpixel
#define sys_my_buffer_char_blt    my_buffer_char_blt
#define sys_my_buffer_horizontal_line    my_buffer_horizontal_line
#define sys_drawDataRectangle   drawDataRectangle
#define sys_refresh_screen  refresh_screen
#define sys_open open
#define sys_close close
#define sys_show_window_rect  show_window_rect
#define sys_set_up_cursor set_up_cursor
#define sys_system_dispatch_to_procedure system_dispatch_to_procedure
#define sys_system_procedure system_procedure
#define sys_resize_window resize_window
#define sys_redraw_window redraw_window
#define sys_replace_window replace_window
#define sys_MaximizeWindow MaximizeWindow
#define sys_MinimizeWindow MinimizeWindow
#define sys_windowGetForegroundWindow windowGetForegroundWindow
#define sys_windowSetForegroundWindow windowSetForegroundWindow
#define sys_RegisterWindow RegisterWindow
#define sys_CloseWindow CloseWindow
#define sys_set_active_window set_active_window
#define sys_get_active_window get_active_window
#define sys_SetFocus  SetFocus 
#define sys_KillFocus KillFocus
#define sys_servicesPutChar servicesPutChar
#define sys_windowSendMessage windowSendMessage
#define sys_create_request create_request
#define sys_do_fork_process do_fork_process
#define sys_show_currentprocess_info show_currentprocess_info
#define sys_do_wait do_wait
#define sys_Down Down
#define sys_Up   Up
#define sys_processTesting processTesting
#define sys_SelectForExecution SelectForExecution
#define sys_windowGetMessage windowGetMessage
#define sys_windowGetLong1   windowGetLong1
#define sys_windowGetLong2   windowGetLong2
#define sys_systemReboot systemReboot
#define sys_windowUpdateWindow windowUpdateWindow
#define sys_windowSelectColorScheme windowSelectColorScheme
#define sys_portsx86_IN portsx86_IN
#define sys_portsx86_OUT portsx86_OUT
#define sys_systemLinkDriver systemLinkDriver
#define sys_draw_text draw_text
#define sys_fgetc fgetc
#define sys_thread_getchar thread_getchar
#define sys_keyboardGetKeyState keyboardGetKeyState
#define sys_get_scancode get_scancode
#define sys_set_current_keyboard_responder set_current_keyboard_responder
#define sys_get_current_keyboard_responder get_current_keyboard_responder
#define sys_set_current_mouse_responder set_current_mouse_responder
#define sys_get_current_mouse_responder get_current_mouse_responder
#define sys_getClientAreaRect getClientAreaRect
#define sys_setClientAreaRect setClientAreaRect
#define sys_grid grid
#define sys_MainMenu MainMenu
#define sys_executive_gramado_core_init_execve executive_gramado_core_init_execve
#define sys_create_socket create_socket
#define sys_getSocketIP getSocketIP
#define sys_getSocketPort getSocketPort
#define sys_update_socket update_socket
#define sys_fs_print_process_pwd fs_print_process_pwd
#define sys_fsListFiles fsListFiles
#define sys_KiSearchFile KiSearchFile
#define sys_fsUpdateWorkingDiretoryString fsUpdateWorkingDiretoryString
#define sys_fsLoadFileFromCurrentTargetDir fsLoadFileFromCurrentTargetDir
#define sys_fs_pathname_backup fs_pathname_backup
#define sys_fsList fsList
#define sys_fsGetFileSize fsGetFileSize
#define sys_GetProcessHeapStart GetProcessHeapStart
#define sys_feof feof
#define sys_ferror ferror
#define sys_fseek fseek
#define sys_fputc fputc
#define sys_gc gc
#define sys_signalSend signalSend
#define sys_block_for_a_reason block_for_a_reason
#define sys_systemGetTerminalWindow systemGetTerminalWindow
#define sys_systemSetTerminalWindow systemSetTerminalWindow
#define sys_create_timer create_timer
#define sys_get_systime_info get_systime_info
#define sys_get_time get_time
#define sys_get_date get_date
#define sys_fclose fclose
#define sys_fflush fflush
#define sys_fprintf fprintf
#define sys_fputs fputs
#define sys_get_cursor_x get_cursor_x
#define sys_get_cursor_y get_cursor_y
#define sys_timerEnableTextCursor timerEnableTextCursor
#define sys_timerDisableTextCursor timerDisableTextCursor
#define sys_fopen fopen
#define sys_systemGetSystemMetrics systemGetSystemMetrics
#define sys_diskShowCurrentDiskInfo diskShowCurrentDiskInfo
#define sys_volumeShowCurrentVolumeInfo volumeShowCurrentVolumeInfo
#define sys_memoryShowMemoryInfo memoryShowMemoryInfo
#define sys_systemShowDevicesInfo systemShowDevicesInfo
#define sys_KiInformation KiInformation







//
// End
//
