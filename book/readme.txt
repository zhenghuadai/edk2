����Դ����Ĳ���(EDK2���µ��汾��13087)��
0. svn co https://svn.code.sf.net/p/edk2/code/trunk/edk2 -r 13087
1. ��EDK2��Ŀ¼�½���uefiĿ¼��
2. ���ļ���book���Ƶ�uefiĿ¼��
3. ��CMD������
4. ���������л���EDK2��Ŀ¼
5. ��������ִ��
    edksetup.bat --nt32
6. ��������ִ��
    build -p uefi\book\Nt32Pkg\Nt32Pkg.dsc
    build -p uefi\book\AppPkg\AppPkg.dsc
7. ��StdLib\Include\sys\EfiCdefs.h��330��ע�͵�
    #ifdef _NATIVE_WCHAR_T_DEFINED
    // #error You must specify /Zc:wchar_t- to the compiler to turn off intrinsic nwchar_t.
    #endif
8.  build -p uefi\book\GUIPkg\GUIPkg.dsc

����Դ����Ĳ���(UDK2014)��
1. ��EDK2��Ŀ¼�½���uefiĿ¼��
2. ���ļ���book���Ƶ�uefiĿ¼��
3. ��CMD������
4. ���������л���EDK2��Ŀ¼
5. ��������ִ��
    edksetup.bat --nt32
6. ��uefi\book\Nt32Pkg\Nt32Pkg.inc�ļ���ӵ�Nt32Pkg\Nt32Pkg.dscĩβ
    type uefi\book\Nt32Pkg\Nt32Pkg.inc >> Nt32Pkg\Nt32Pkg.dsc
6. ��������ִ��
    build

����Դ����Ĳ���(EDK2���µ��汾��16682)��
0. svn co https://svn.code.sf.net/p/edk2/code/trunk/edk2 -r 13087
1. ��EDK2��Ŀ¼�½���uefiĿ¼��
2. ���ļ���book���Ƶ�uefiĿ¼��
3. ��CMD������
4. ���������л���EDK2��Ŀ¼
5. ��������ִ��
    edksetup.bat --nt32
6. ��StdLib\Include\sys\EfiCdefs.h��330��ע�͵�
    #ifdef _NATIVE_WCHAR_T_DEFINED
    // #error You must specify /Zc:wchar_t- to the compiler to turn off intrinsic nwchar_t.
    #endif
7. ����Nt32Pkg
   7.1 ��uefi\book\Nt32Pkg\Nt32Pkg-2.4.inc�ļ���ӵ�Nt32Pkg\Nt32Pkg.dscĩβ
       type uefi\book\Nt32Pkg\Nt32Pkg-2.4.inc >> Nt32Pkg\Nt32Pkg.dsc
   7.2 ��������ִ��
       build -p Nt32Pkg\Nt32Pkg.dsc
8. ����AppPkg
   8.1 ��uefi\book\AppPkg\AppPkg-2.4.inc�ļ���ӵ�AppPkg\AppPkg.dscĩβ
       type uefi\book\AppPkg\AppPkg-2.4.inc >> AppPkg\AppPkg.dsc
   8.2 build -p AppPkg\AppPkg.dsc


Դ�ļ�����
��1��
��2��
��3��
  infs\
��4��  
��5��
  systemtable\
��6��
  Event\
  mouse\
��7��
  disk\
  FileIo\
��8��
  ffmpeg\
��9��
  auido\
��10��
  GcppPkg\
  CppPkg\
��11��
  Guibasics\
��12��
  GUIPkg\
  ffmpeg\ffplayer\
��13��
  multitask\
��14��
  Network\
��15��
  sstdPkg\
  std\
��16��
  Shell\
