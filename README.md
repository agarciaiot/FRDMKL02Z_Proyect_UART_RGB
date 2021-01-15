# FRDMKL02Z_Proyect_UART_RGB (Proyecto Modulo 04 Semana 02)

## Descripción:

_Control de Estado del LED RGB (GPIOB) de la FREESCALE FRDM-KL02Z mediante caracteres ingresados a través del puerto Serial (UART0) e impresos en Terminal Serial_

## Construido en:

_Para la programación y pruebas se usó la plataforma:_

* [FRDM-KL02Z: Freedom Development Platform for the Kinetis® KL02 Family](https://www.nxp.com/design/development-boards/freedom-development-boards/mcu-boards/freedom-development-platform-for-the-kinetis-kl02-family:FRDM-KL02Z) - MCU Board (KL02Z) | Utra-Low-Power

## Construido con:

_Para la ejecución y desarrollo de este proyecto se utilizaron las siguientes herramientas:_

* [MCUXpresso IDE v11.2.1 [Build 4149] [2020-10-07]](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE) - IDE (Integrated Development Environment) usado
* [SourceTree 3.4.1 [2020-12-31]](https://www.sourcetreeapp.com/) - Git GUI usado para el control de versiones

_Otras herramientas tipo Serial Terminal GUI para pruebas externas al IDE_
* [Docklight v2.3.26](https://docklight.de/downloads/)
* [QCOM v1.6 (15.01.16.10.100) [Rev. 1.1] [2015-03-30]](https://www.quectel.com/product/ec25.htm)

## Librerías utilizadas/requeridas:

_Las que están incluidas en el repositorio y las librerías internas de la placa de desarrollo_

## Pre-requisitos:

* Instalación previa del programa **MCUXpresso IDE de NXP** en la versión referenciada

* Consultar de la documentación de desarrollo y gestión sobre el programa ([MCUXpresso Integrated Development Environment (IDE)](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE?&tab=Documentation_Tab&linkline=Users-Guide))

* Instalación en el programa del SDK necesario para le ejecución del proyecto con configuración activa ([MCUXpresso Software Development Kit (SDK)](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-software-development-kit-sdk:MCUXpresso-SDK))

## Instalación:

_Para descargar del respositorio en archivo *.rar se recomienda seguir los pasos siguientes para prevenir errores:_

* Descomprimir el archivo *.rar en una ubicación conocida y copiar la ruta de acceso al espacio de trabajo (por simplicidad se recomienda la ruta del sistema: C:\FRDMKL02Z_Proyect_UART_RGB-main)

* Iniciar el Programa **MCUXpresso IDE** y en el lanzador de espacio de trabajo _(Workspace)_ asignar la ruta anterior, si ya posee una ruta de espacio de trabajo por defecto iniciar el programa en esa ruta y en la barra de menús ir a _File > Switch Workspace > Other_ digitar la ruta asignada lanzar en _Launch_, el programa se reiniciará y se lanzará en la ruta asignada como Workspace

* Para importar el proyecto en la barra de menús ir a _File > Import_ en la ventana _Import_ seleccionar el desplegable _General > Existing Projects into Workspace_ en _Browse..._ seleccionar la carpeta del proyecto (MKL02Z32VFM4_UART0_GPIOB), aparecerá en la lista en el cuadro Projects: seleccionaro y luego dar en _Finish_, se iniciará la carga de los archivos y sdk necesarios para la ejecución

* Una vez cargado el proyecto presione _Ctrl+B_ para iniciar la primera depuración y comprobar que no existan errores.

## Ejecución de Pruebas:

_Se ejecutaron pruebas de envío/recepción de datos sobre los terminales Seriales:_

* Docklight v2.3.26
* QCOM v1.6

## Autores:

* **Álvaro García** - *Trabajo Inicial* - [agarciaiot](https://github.com/agarciaiot)
* **Ernesto Rincón** - *Documentación y Asesoría* - [ErnestoARC](https://github.com/ErnestoARC)

## Licencia:

Este proyecto está bajo la Licencia gratuita (MIT License) - mira el archivo [LICENSE.md](LICENSE.md) para detalles

Desarrollado por [agarciaiot](https://github.com/agarciaiot) para el Diplomado de IoT (Internet of Things, en Español: _**Internet de las Cosas**_) del Programa de [Ingeniería Electrónica en la Universidad del Magdalena](https://www.unimagdalena.edu.co/presentacionPrograma/Programa/1005).
