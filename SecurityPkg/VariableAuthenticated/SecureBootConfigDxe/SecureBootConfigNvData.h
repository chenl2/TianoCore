/** @file
  Header file for NV data structure definition.

Copyright (c) 2011 - 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __SECUREBOOT_CONFIG_NV_DATA_H__
#define __SECUREBOOT_CONFIG_NV_DATA_H__

#include <Guid/HiiPlatformSetupFormset.h>
#include <Guid/SecureBootConfigHii.h>

//
// Used by VFR for form or button identification
//
#define SECUREBOOT_CONFIGURATION_VARSTORE_ID  0x0001
#define SECUREBOOT_CONFIGURATION_FORM_ID      0x01
#define FORMID_SECURE_BOOT_OPTION_FORM        0x02
#define FORMID_SECURE_BOOT_PK_OPTION_FORM     0x03
#define FORMID_SECURE_BOOT_KEK_OPTION_FORM    0x04
#define FORMID_SECURE_BOOT_DB_OPTION_FORM     0x05
#define FORMID_SECURE_BOOT_DBX_OPTION_FORM    0x06
#define FORMID_ENROLL_PK_FORM                 0x07
#define SECUREBOOT_ADD_PK_FILE_FORM_ID        0x08
#define FORMID_ENROLL_KEK_FORM                0x09
#define FORMID_DELETE_KEK_FORM                0x0a
#define SECUREBOOT_ENROLL_SIGNATURE_TO_DB     0x0b
#define SECUREBOOT_ENROLL_SIGNATURE_TO_DBX    0x0c
#define FORMID_SECURE_BOOT_DBT_OPTION_FORM    0x0d
#define SECUREBOOT_ENROLL_SIGNATURE_TO_DBT    0x0e
#define SECUREBOOT_SHOW_SIGNATURE_LIST_FORM	  0x0f
#define SECUREBOOT_SHOW_SIGNATURE_DATA_FORM   0x10

#define SECURE_BOOT_MODE_CUSTOM               0x01
#define SECURE_BOOT_MODE_STANDARD             0x00

#define KEY_SECURE_BOOT_ENABLE                0x1000
#define KEY_SECURE_BOOT_MODE                  0x1001
#define KEY_VALUE_SAVE_AND_EXIT_DB            0x1002
#define KEY_VALUE_NO_SAVE_AND_EXIT_DB         0x1003
#define KEY_VALUE_SAVE_AND_EXIT_PK            0x1004
#define KEY_VALUE_NO_SAVE_AND_EXIT_PK         0x1005
#define KEY_VALUE_SAVE_AND_EXIT_KEK           0x1008
#define KEY_VALUE_NO_SAVE_AND_EXIT_KEK        0x1009
#define KEY_VALUE_SAVE_AND_EXIT_DBX           0x100a
#define KEY_VALUE_NO_SAVE_AND_EXIT_DBX        0x100b
#define KEY_HIDE_SECURE_BOOT                  0x100c
#define KEY_VALUE_SAVE_AND_EXIT_DBT           0x100d
#define KEY_VALUE_NO_SAVE_AND_EXIT_DBT        0x100e
#define KEY_VALUE_DELETE_ALL_SIGNATURE_LIST   0x100f
#define KEY_VALUE_DELETE_GOTO_DB_FORM		      0x1010
#define KEY_VALUE_DELETE_GOTO_DBX_FORM		    0x1011
#define KEY_VALUE_DELETE_GOTO_DBT_FORM        0x1012
#define KEY_VALUE_DELETE_ALL_SIGNATURE_DATA   0x1013
#define KEY_VALUE_DELETE_CHECK_SIGNATURE_DATA 0x1014

#define KEY_SECURE_BOOT_OPTION                0x1100
#define KEY_SECURE_BOOT_PK_OPTION             0x1101
#define KEY_SECURE_BOOT_KEK_OPTION            0x1102
#define KEY_SECURE_BOOT_DB_OPTION             0x1103
#define KEY_SECURE_BOOT_DBX_OPTION            0x1104
#define KEY_SECURE_BOOT_DELETE_PK             0x1105
#define KEY_ENROLL_PK                         0x1106
#define KEY_ENROLL_KEK                        0x1107
#define KEY_DELETE_KEK                        0x1108
#define KEY_SECURE_BOOT_KEK_GUID              0x110a
#define KEY_SECURE_BOOT_SIGNATURE_GUID_DB     0x110b
#define KEY_SECURE_BOOT_SIGNATURE_GUID_DBX    0x110c
#define KEY_SECURE_BOOT_DBT_OPTION            0x110d
#define KEY_SECURE_BOOT_SIGNATURE_GUID_DBT    0x110e

#define LABEL_KEK_DELETE                      0x1200
#define LABEL_SIGNATURE_LIST_START			      0x1201
#define LABEL_SIGNATURE_DATA_START            0x1202
#define LABEL_END                             0xffff


#define SECURE_BOOT_MAX_ATTEMPTS_NUM          255

#define CONFIG_OPTION_OFFSET                  0x2000

#define OPTION_CONFIG_QUESTION_ID             0x2000
#define OPTION_CONFIG_RANGE                   0x1000

//
// Question ID 0x2000 ~ 0x2FFF is for KEK
//
#define OPTION_DEL_KEK_QUESTION_ID            0x2000
//
// Question ID 0x3000 ~ 0x3FFF is for signature list of DB,DBX,DBT
//
#define OPTION_SIGNATURE_LIST_QUESTION_ID	    0x3000
//
// Question ID 0x4000 ~ 0x4FFF is for signature data of DB,DBX,DBT
//
#define OPTION_SIGNATURE_DATA_QUESTION_ID     0x4000

#define SECURE_BOOT_GUID_SIZE                 36
#define SECURE_BOOT_GUID_STORAGE_SIZE         37

#define UNKNOWN_FILE_TYPE                     0
#define X509_CERT_FILE_TYPE                   1
#define PE_IMAGE_FILE_TYPE                    2
#define AUTHENTICATION_2_FILE_TYPE            3

//
// Nv Data structure referenced by IFR
//
typedef struct {
  BOOLEAN AttemptSecureBoot;   // Attempt to enable/disable Secure Boot
  BOOLEAN HideSecureBoot;      // Hiden Attempt Secure Boot
  CHAR16  SignatureGuid[SECURE_BOOT_GUID_STORAGE_SIZE];
  BOOLEAN PhysicalPresent;     // If a Physical Present User
  UINT8   SecureBootMode;      // Secure Boot Mode: Standard Or Custom
  BOOLEAN DeletePk;
  BOOLEAN HasPk;               // If Pk is existed it is true
  BOOLEAN AlwaysRevocation;    // If the certificate is always revoked. Revocation time is hidden
  UINT8   CertificateFormat;   // The type of the certificate
  EFI_HII_DATE RevocationDate; // The revocation date of the certificate
  EFI_HII_TIME RevocationTime; // The revocation time of the certificate
  UINT8   FileEnrollType;      // File type of sigunature enroll
  BOOLEAN HasSignatureList;    // The variable has at least one signature list.
  UINT8   CheckedDataCount;    // Record how many data item has been checked.
} SECUREBOOT_CONFIGURATION;

#endif
