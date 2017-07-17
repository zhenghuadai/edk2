#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiLib.h>
#define INIT_NAME_BUFFER_SIZE  128
#define INIT_DATA_BUFFER_SIZE  1024
EFI_STATUS UefiMain (
        IN EFI_HANDLE        ImageHandle,
        IN EFI_SYSTEM_TABLE  *SystemTable
        )
{
    EFI_STATUS Status;
    CHAR16                    *FoundVarName;
    EFI_GUID                  FoundVarGuid;
    UINT8                     *DataBuffer;
    UINTN                     DataSize;
    UINT32                    Atts;
    UINTN                     NameBufferSize; // Allocated Name buffer size
    UINTN                     NameSize;
    CHAR16                    *OldName;
    UINTN                     OldNameBufferSize;
    UINTN                     DataBufferSize; // Allocated data buffer size

    NameBufferSize = INIT_NAME_BUFFER_SIZE;// 128
    DataBufferSize = INIT_DATA_BUFFER_SIZE;// 1024
    // Ϊ�����������ڴ棬���ұ����ʼ��Ϊ0�����ٵ�һ���ַ�����Ϊ0����
    FoundVarName   = AllocateZeroPool (NameBufferSize);
    if (FoundVarName == NULL) {
        return (EFI_OUT_OF_RESOURCES);
    }  
    DataBuffer     = AllocatePool (DataBufferSize);
    if (DataBuffer == NULL) {
        FreePool (FoundVarName);
        return (EFI_OUT_OF_RESOURCES);
    }

    for (;;){
        NameSize  = NameBufferSize;
        Status    = gRT->GetNextVariableName (&NameSize, FoundVarName, &FoundVarGuid);
        if (Status == EFI_BUFFER_TOO_SMALL) {
            // ������������������·����ڴ������ִ��GetNextVariableName
            OldName           = FoundVarName;
            OldNameBufferSize = NameBufferSize;
            // �����㹻����ڴ�
            NameBufferSize = NameSize > NameBufferSize*2 ? NameSize : NameBufferSize * 2;
            FoundVarName           = AllocateZeroPool (NameBufferSize);
            if (FoundVarName == NULL) {
                Status = EFI_OUT_OF_RESOURCES;
                FreePool (OldName);
                break;
            }
            //����ǰ�������ִӾɻ��������Ƶ��»�������
            CopyMem (FoundVarName, OldName, OldNameBufferSize);
            FreePool (OldName);
            NameSize = NameBufferSize;
            // ����ִ��GetNextVariableName
            Status = gRT->GetNextVariableName (&NameSize, FoundVarName, &FoundVarGuid);
        }
        if (Status == EFI_NOT_FOUND) {
            // ����������ݿ�ĩβʱ�˳�ѭ��
            break;
        }
        Print(L"%s\n",  FoundVarName);
        //�ҵ�һ���µı�������ȡ�ñ�����ֵ�����ԡ�
        DataSize  = DataBufferSize;
        Status    = gRT->GetVariable (FoundVarName, &FoundVarGuid, &Atts, &DataSize, DataBuffer);
        if (Status == EFI_BUFFER_TOO_SMALL) {
        }
    }// End for(;;)

    return Status;
}
