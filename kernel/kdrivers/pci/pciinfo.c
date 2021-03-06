
//pciinfo.c


#include <kernel.h>

//
// Class strings.
//

//Obs: parece que outra forma de lista é mais apropriado.
static const char* pci_class_strings[] = {
	"Unknow",                              //0x00 (Pre 2.0 device)
	"Mass Storage Controller",             //0x01
	"Network Controller",                  //0x02
	"Display Controller",                  //0x03
	"Multimedia Controller",               //0x04 (Multimedia Device)
	"Memory Controller",                   //0x05
	"Bridge Device",                       //0x06
	"Simple Communication Controller",     //0x07
	"Base System Peripheral",              //0x08
	"Input Device",                        //0x09
	"Docking Station",                     //0x0a
	"Processor",                           //0x0b
	"Serial Bus Controller",               //0x0c
	"Wireless Controller",                 //0x0d
	"Intelligent IO Controllers",          //0x0e
	"Satellite Communication Controller",  //0x0f
	"Encryption Decryption Controller",    //0x10
	"Data Acquisition and Signal Processing Controller",
	0
	//"Processing Accelerators",      //0x12
	//"Non-Essential Instrumentation" //0x13
	//Daqui pra frente está reservado.
	//0xff (Device does not fit in any defined classes)
};


/*
 * Mostra informações sobre um dispositivo PCI da lista.
 */

int pciShowDeviceInfo (int number){
	
    struct pci_device_d *D;
  
	if(number < 0 || number > 32)
	{
		return 0;
	}
	
	//Pega um ponteiro de estrutura na lista.
	D = (void *) pcideviceList[number];
	
	//Checa se o ponteiro é válido.
	if( (void *) D != NULL )
	{
		if (D->magic == 1234)
		{
			
			printf ("Vendor={%x} Device={%x} ClassCode={%x} IntLine={%x} \n",
			    D->Vendor, D->Device, D->classCode, D->irq_line );
		}
	}
	//Nothing
	return 0;
}




/*
 ****************************************************************************
 * pciInfo:
 *     Mostra as informações salvas nas estruturas da lista de dispositivos. 
 *
 * 0x2668	82801FB (ICH6) High Definition Audio Controller 0x8086	Intel Corporation.
 * 0x2829	Intel(R) ICH8M SATA AHCI Controller	0x8086	Intel Corporation.
 * 0x1237	PCI & Memory	0x8086	Intel Corporation.
 * ...
 *
 */

int pciInfo (){
	
	int i;
	int Max = 32;

	struct pci_device_d *D;
	
	printf("pciInfo: \n");
	
	//
	// Uma lista com no máximo 32 ponteiros para estrutura de dispositivo pci.
	//
	
	for ( i=0; i<Max; i++ )
	{
		//Pega um ponteiro de estrutura na lista.
		D = (void *) pcideviceList[i];
		
		//Checa se o ponteiro é válido.
		if( (void *) D != NULL )
		{
			//@todo: Mostrar mais informações.
			if (D->magic == 1234)
			{
				printf("\n [%d/%d/%d] Vendor=%x Device=%x Class=%s SubClass=%x iLine=%d iPin=%d \n",
				       D->bus, D->dev , D->func,
					   D->Vendor, D->Device, 
					   pci_class_strings[ D->classCode ], D->subclass, 
					   D->irq_line, D->irq_pin );
			};
		};
	};
	
	printf("done\n");
	return (int) 0; 
}








