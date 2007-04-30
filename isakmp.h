/* ISAKMP constants.
   Copyright (C) 2002  Geoffrey Keating

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   $Id$
*/

#ifndef __ISAKMP_H__
#define __ISAKMP_H__

/* Flag bits for header.  */
#define ISAKMP_FLAG_E	0x1
#define ISAKMP_FLAG_C	0x2
#define ISAKMP_FLAG_A	0x4

/* Payload types */
enum isakmp_payload_enum {
	ISAKMP_PAYLOAD_NONE = 0,
	ISAKMP_PAYLOAD_SA,
	ISAKMP_PAYLOAD_P,
	ISAKMP_PAYLOAD_T,
	ISAKMP_PAYLOAD_KE,
	ISAKMP_PAYLOAD_ID,
	ISAKMP_PAYLOAD_CERT,
	ISAKMP_PAYLOAD_CR,
	ISAKMP_PAYLOAD_HASH,
	ISAKMP_PAYLOAD_SIG,
	ISAKMP_PAYLOAD_NONCE,
	ISAKMP_PAYLOAD_N,
	ISAKMP_PAYLOAD_D,
	ISAKMP_PAYLOAD_VID,
	ISAKMP_PAYLOAD_MODECFG_ATTR,
	ISAKMP_PAYLOAD_NAT_D,
	ISAKMP_PAYLOAD_NAT_OA,
	ISAKMP_PAYLOAD_NAT_D_OLD = 0x82
};

/* Exchange types.  */
enum isakmp_exchange_enum {
	ISAKMP_EXCHANGE_NONE = 0,
	ISAKMP_EXCHANGE_BASE,
	ISAKMP_EXCHANGE_IDENTITY,
	ISAKMP_EXCHANGE_AUTH_ONLY,
	ISAKMP_EXCHANGE_AGGRESSIVE,
	ISAKMP_EXCHANGE_INFORMATIONAL,
	ISAKMP_EXCHANGE_MODECFG_TRANSACTION,
	ISAKMP_EXCHANGE_IKE_QUICK = 32,
	ISAKMP_EXCHANGE_IKE_NEW_GROUP
};

/* DOI types.  */
enum isakmp_doi_enum {
	ISAKMP_DOI_GENERIC = 0,
	ISAKMP_DOI_IPSEC
};

/* Notify message types.  */
enum isakmp_notify_enum {
	ISAKMP_N_INVALID_PAYLOAD_TYPE = 1,
	ISAKMP_N_DOI_NOT_SUPPORTED,
	ISAKMP_N_SITUATION_NOT_SUPPORTED,
	ISAKMP_N_INVALID_COOKIE,
	ISAKMP_N_INVALID_MAJOR_VERSION,
	ISAKMP_N_INVALID_MINOR_VERSION,
	ISAKMP_N_INVALID_EXCHANGE_TYPE,
	ISAKMP_N_INVALID_FLAGS,
	ISAKMP_N_INVALID_MESSAGE_ID,
	ISAKMP_N_INVALID_PROTOCOL_ID,
	ISAKMP_N_INVALID_SPI,
	ISAKMP_N_INVALID_TRANSFORM_ID,
	ISAKMP_N_ATTRIBUTES_NOT_SUPPORTED,
	ISAKMP_N_NO_PROPOSAL_CHOSEN,
	ISAKMP_N_BAD_PROPOSAL_SYNTAX,
	ISAKMP_N_PAYLOAD_MALFORMED,
	ISAKMP_N_INVALID_KEY_INFORMATION,
	ISAKMP_N_INVALID_ID_INFORMATION,
	ISAKMP_N_INVALID_CERT_ENCODING,
	ISAKMP_N_INVALID_CERTIFICATE,
	ISAKMP_N_CERT_TYPE_UNSUPPORTED,
	ISAKMP_N_INVALID_CERT_AUTHORITY,
	ISAKMP_N_INVALID_HASH_INFORMATION,
	ISAKMP_N_AUTHENTICATION_FAILED,
	ISAKMP_N_INVALID_SIGNATURE,
	ISAKMP_N_ADDRESS_NOTIFICATION,
	ISAKMP_N_NOTIFY_SA_LIFETIME,
	ISAKMP_N_CERTIFICATE_UNAVAILABLE,
	ISAKMP_N_UNSUPPORTED_EXCHANGE_TYPE,
	ISAKMP_N_UNEQUAL_PAYLOAD_LENGTHS,
	ISAKMP_N_CONNECTED = 16384,
	ISAKMP_N_IPSEC_RESPONDER_LIFETIME = 24576,
	ISAKMP_N_IPSEC_REPLAY_STATUS,
	ISAKMP_N_IPSEC_INITIAL_CONTACT,
	ISAKMP_N_CISCO_LOAD_BALANCE = 40501
};

/* IKE attribute types.  */
enum ike_attr_enum {
	IKE_ATTRIB_ENC = 1,
	IKE_ATTRIB_HASH,
	IKE_ATTRIB_AUTH_METHOD,
	IKE_ATTRIB_GROUP_DESC,
	IKE_ATTRIB_GROUP_TYPE,
	IKE_ATTRIB_GROUP_PRIME,
	IKE_ATTRIB_GROUP_GEN_1,
	IKE_ATTRIB_GROUP_GEN_2,
	IKE_ATTRIB_GROUP_CURVE_A,
	IKE_ATTRIB_GROUP_CURVE_B,
	IKE_ATTRIB_LIFE_TYPE,
	IKE_ATTRIB_LIFE_DURATION,
	IKE_ATTRIB_PRF,
	IKE_ATTRIB_KEY_LENGTH,
	IKE_ATTRIB_FIELD_SIZE,
	IKE_ATTRIB_GROUP_ORDER,
	IKE_ATTRIB_BLOCK_SIZE
};

/* IKE encryption algorithm IDs.  */
enum ike_enc_enum {
	IKE_ENC_NO_CBC = 0,
	IKE_ENC_DES_CBC,
	IKE_ENC_IDEA_CBC,
	IKE_ENC_BLOWFISH_CBC,
	IKE_ENC_RC5_R16_B16_CBC,
	IKE_ENC_3DES_CBC,
	IKE_ENC_CAST_CBC,
	IKE_ENC_AES_CBC
};

/* IKE hash algorithm IDs.  */
enum ike_hash_enum {
	IKE_HASH_MD5 = 1,
	IKE_HASH_SHA,
	IKE_HASH_TIGER,
	IKE_HASH_SHA2_256,
	IKE_HASH_SHA2_384,
	IKE_HASH_SHA2_512
};

/* IKE authentication method IDs.  */
enum ike_auth_enum {
	IKE_AUTH_PRESHARED = 1,
	IKE_AUTH_DSS,
	IKE_AUTH_RSA_SIG,
	IKE_AUTH_RSA_ENC,
	IKE_AUTH_RSA_ENC_2,
	IKE_AUTH_EL_GAMAL_ENC,
	IKE_AUTH_EL_GAMAL_ENC_REV,
	IKE_AUTH_ECDSA_SIG,
	IKE_AUTH_XAUTHInitPreShared = 65001,
	IKE_AUTH_XAUTHRespPreShared,
	IKE_AUTH_XAUTHInitDSS,
	IKE_AUTH_XAUTHRespDSS,
	IKE_AUTH_XAUTHInitRSA,
	IKE_AUTH_XAUTHRespRSA,
	IKE_AUTH_XAUTHInitRSAEncryption,
	IKE_AUTH_XAUTHRespRSAEncryption,
	IKE_AUTH_XAUTHInitRSARevisedEncryption,
	IKE_AUTH_XAUTHRespRSARevisedEncryption
};

/* IKE group IDs.  */
enum ike_group_enum {
	IKE_GROUP_MODP_768 = 1,
	IKE_GROUP_MODP_1024,
	IKE_GROUP_EC2N_155,
	IKE_GROUP_EC2N_185,
	IKE_GROUP_MODP_1536,
	IKE_GROUP_EC2N_163sect,
	IKE_GROUP_EC2N_163K,
	IKE_GROUP_EC2N_283sect,
	IKE_GROUP_EC2N_283K,
	IKE_GROUP_EC2N_409sect,
	IKE_GROUP_EC2N_409K,
	IKE_GROUP_EC2N_571sect,
	IKE_GROUP_EC2N_571K
};

/* IKE group type IDs.  */
enum ike_group_type_enum {
	IKE_GROUP_TYPE_MODP = 1,
	IKE_GROUP_TYPE_ECP,
	IKE_GROUP_TYPE_EC2N
};

/* IKE life type IDs.  */
enum ike_life_enum {
	IKE_LIFE_TYPE_SECONDS = 1,
	IKE_LIFE_TYPE_K
};

/* IPSEC situation masks.  */
enum isakmp_ipsec_sit_enum {
	ISAKMP_IPSEC_SIT_IDENTITY_ONLY = 0x1,
	ISAKMP_IPSEC_SIT_SECRECY       = 0x2,
	ISAKMP_IPSEC_SIT_INTEGRITY     = 0x4
};

/* IPSEC Identification types.  */
enum isakmp_ipsec_id_enum {
	ISAKMP_IPSEC_ID_RESERVED = 0,
	ISAKMP_IPSEC_ID_IPV4_ADDR,
	ISAKMP_IPSEC_ID_FQDN,
	ISAKMP_IPSEC_ID_USER_FQDN,
	ISAKMP_IPSEC_ID_IPV4_ADDR_SUBNET,
	ISAKMP_IPSEC_ID_IPV6_ADDR,
	ISAKMP_IPSEC_ID_IPV6_ADDR_SUBNET,
	ISAKMP_IPSEC_ID_IPV4_ADDR_RANGE,
	ISAKMP_IPSEC_ID_IPV6_ADDR_RANGE,
	ISAKMP_IPSEC_ID_DER_ASN1_DN,
	ISAKMP_IPSEC_ID_DER_ASN1_GN,
	ISAKMP_IPSEC_ID_KEY_ID
};

/* IPSEC protocol IDs.  */
enum isakmp_ipsec_proto_enum {
	ISAKMP_IPSEC_PROTO_RESERVED = 0,
	ISAKMP_IPSEC_PROTO_ISAKMP,
	ISAKMP_IPSEC_PROTO_IPSEC_AH,
	ISAKMP_IPSEC_PROTO_IPSEC_ESP,
	ISAKMP_IPSEC_PROTO_IPCOMP,
	ISAKMP_IPSEC_PROTO_MODECFG = 512 /* hack for simplicity in debug code */
};

/* IPSEC transform IDs.  */
enum isakmp_ipsec_key_enum {
	ISAKMP_IPSEC_KEY_RESERVED = 0,
	ISAKMP_IPSEC_KEY_IKE
};

/* IPSEC AH IDs.  */
enum isakmp_ipsec_ah_enum {
	ISAKMP_IPSEC_AH_RESERVED = 0,
	ISAKMP_IPSEC_AH_MD5 = 2,
	ISAKMP_IPSEC_AH_SHA,
	ISAKMP_IPSEC_AH_DES,
	ISAKMP_IPSEC_AH_SHA2_256,
	ISAKMP_IPSEC_AH_SHA2_384,
	ISAKMP_IPSEC_AH_SHA2_512,
	ISAKMP_IPSEC_AH_RIPEMD
};

/* IPSEC ESP IDs.  */
enum isakmp_ipsec_esp_enum {
	ISAKMP_IPSEC_ESP_RESERVED = 0,
	ISAKMP_IPSEC_ESP_DES_IV64,
	ISAKMP_IPSEC_ESP_DES,
	ISAKMP_IPSEC_ESP_3DES,
	ISAKMP_IPSEC_ESP_RC5,
	ISAKMP_IPSEC_ESP_IDEA,
	ISAKMP_IPSEC_ESP_CAST,
	ISAKMP_IPSEC_ESP_BLOWFISH,
	ISAKMP_IPSEC_ESP_3IDEA,
	ISAKMP_IPSEC_ESP_DES_IV32,
	ISAKMP_IPSEC_ESP_RC4,
	ISAKMP_IPSEC_ESP_NULL,
	ISAKMP_IPSEC_ESP_AES,
	ISAKMP_IPSEC_ESP_AES_128_CTR,
	ISAKMP_IPSEC_ESP_AES_MARS = 249,
	ISAKMP_IPSEC_ESP_AES_RC6,
	ISAKMP_IPSEC_ESP_AES_RIJNDAEL,
	ISAKMP_IPSEC_ESP_AES_SERPENT,
	ISAKMP_IPSEC_ESP_AES_TWOFISH
};

/* IPSEC attribute types.  */
enum isakmp_ipsec_attr_enum {
	ISAKMP_IPSEC_ATTRIB_SA_LIFE_TYPE = 1,
	ISAKMP_IPSEC_ATTRIB_SA_LIFE_DURATION,
	ISAKMP_IPSEC_ATTRIB_GROUP_DESC,
	ISAKMP_IPSEC_ATTRIB_ENCAP_MODE,
	ISAKMP_IPSEC_ATTRIB_AUTH_ALG,
	ISAKMP_IPSEC_ATTRIB_KEY_LENGTH,
	ISAKMP_IPSEC_ATTRIB_KEY_ROUNDS,
	ISAKMP_IPSEC_ATTRIB_COMP_DICT_SIZE,
	ISAKMP_IPSEC_ATTRIB_COMP_PRIVATE_ALG,
	ISAKMP_IPSEC_ATTRIB_ECN_TUNNEL
};

/* IPSEC compression IDs.  */
enum isakmp_ipsec_ipcomp_enum {
	ISAKMP_IPSEC_IPCOMP_RESERVED = 0,
	ISAKMP_IPSEC_IPCOMP_OUI,
	ISAKMP_IPSEC_IPCOMP_DEFLATE,
	ISAKMP_IPSEC_IPCOMP_LZS,
	ISAKMP_IPSEC_IPCOMP_V42BIS
};

/* IPSEC lifetime attribute values.  */
enum ipsec_life_enum {
	IPSEC_LIFE_SECONDS = 1,
	IPSEC_LIFE_K
};

/* IPSEC encapsulation attribute numbers.  */
enum ipsec_encap_enum {
	IPSEC_ENCAP_TUNNEL = 1,
	IPSEC_ENCAP_TRANSPORT,
	IPSEC_ENCAP_UDP_TUNNEL,
	IPSEC_ENCAP_UDP_TRANSPORT,
	IPSEC_ENCAP_UDP_TUNNEL_OLD = 61443,
	IPSEC_ENCAP_UDP_TRANSPORT_OLD
};

/* IPSEC authentication attribute numbers.  */
enum ipsec_auth_enum {
	IPSEC_AUTH_HMAC_MD5 = 1,
	IPSEC_AUTH_HMAC_SHA,
	IPSEC_AUTH_DES_MAC,
	IPSEC_AUTH_KPDK
};

/* Other numbers.  */
#define ISAKMP_COOKIE_LENGTH		8
#define ISAKMP_VERSION			0x10
/* offsets */
#define ISAKMP_EXCHANGE_TYPE_O		18
#define ISAKMP_I_COOKIE_O		0
#define ISAKMP_R_COOKIE_O		8
#define ISAKMP_MESSAGE_ID_O		20
#define ISAKMP_PAYLOAD_O		28

/* Support for draft-ietf-ipsec-isakmp-xauth-06.txt (yuk).  */
#define XAUTH_VENDOR_ID { 0x09, 0x00, 0x26, 0x89, 0xDF, 0xD6, 0xB7, 0x12 }
/* From dead-peer-detection RFC 3706 */
#define DPD_VENDOR_ID { 0xAF, 0xCA, 0xD7, 0x13, 0x68, 0xA1, 0xF1, 0xC9, \
	0x6B, 0x86, 0x96, 0xFC, 0x77, 0x57, 0x01, 0x00}
#define UNITY_VENDOR_ID { 0x12, 0xF5, 0xF2, 0x8C, 0x45, 0x71, 0x68, 0xA9, \
	0x70, 0x2D, 0x9F, 0xE2, 0x74, 0xCC, 0x01, 0x00 }
#define UNKNOWN_VENDOR_ID { 0x12, 0x6E, 0x1F, 0x57, 0x72, 0x91, 0x15, 0x3B, \
	0x20, 0x48, 0x5F, 0x7F, 0x15, 0x5B, 0x4B, 0xC8 }

/* draft-ietf-ipsec-nat-t-ike-00 */
#define NATT_VENDOR_ID_00 { 0x44, 0x85, 0x15, 0x2d, 0x18, 0xb6, 0xbb, 0xcd, \
	0x0b, 0xe8, 0xa8, 0x46, 0x95, 0x79, 0xdd, 0xcc }
/* draft-ietf-ipsec-nat-t-ike-01 */
#define NATT_VENDOR_ID_01 { 0x16, 0xf6, 0xca, 0x16, 0xe4, 0xa4, 0x06, 0x6d, \
	0x83, 0x82, 0x1a, 0x0f, 0x0a, 0xea, 0xa8, 0x62 }
/* draft-ietf-ipsec-nat-t-ike-02 */
#define NATT_VENDOR_ID_02 { 0xcd, 0x60, 0x46, 0x43, 0x35, 0xdf, 0x21, 0xf8, \
	0x7c, 0xfd, 0xb2, 0xfc, 0x68, 0xb6, 0xa4, 0x48 }
/* draft-ietf-ipsec-nat-t-ike-02\n */
#define NATT_VENDOR_ID_02n { 0x90, 0xCB, 0x80, 0x91, 0x3E, 0xBB, 0x69, 0x6E, \
	0x08, 0x63, 0x81, 0xB5, 0xEC, 0x42, 0x7B, 0x1F }
/* RFC 3947 */
#define NATT_VENDOR_ID_RFC { 0x4A, 0x13, 0x1C, 0x81, 0x07, 0x03, 0x58, 0x45, \
	0x5C, 0x57, 0x28, 0xF2, 0x0E, 0x95, 0x45, 0x2F }

/* Support for draft-ietf-ipsec-isakmp-mode-cfg-05.txt (yuk).  */

enum isakmp_modecfg_cfg_enum {
	ISAKMP_MODECFG_CFG_REQUEST = 1,
	ISAKMP_MODECFG_CFG_REPLY,
	ISAKMP_MODECFG_CFG_SET,
	ISAKMP_MODECFG_CFG_ACK
};

enum isakmp_modecfg_attrib_enum {
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_ADDRESS = 1,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_NETMASK,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_DNS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_NBNS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_ADDRESS_EXPIRY,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_DHCP,
	ISAKMP_MODECFG_ATTRIB_APPLICATION_VERSION,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_ADDRESS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_NETMASK,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_DNS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_NBNS,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_DHCP,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP4_SUBNET,
	ISAKMP_MODECFG_ATTRIB_SUPPORTED_ATTRIBUTES,
	ISAKMP_MODECFG_ATTRIB_INTERNAL_IP6_SUBNET,
	ISAKMP_XAUTH_ATTRIB_TYPE = 0x4088,
	ISAKMP_XAUTH_ATTRIB_USER_NAME,
	ISAKMP_XAUTH_ATTRIB_USER_PASSWORD,
	ISAKMP_XAUTH_ATTRIB_PASSCODE,
	ISAKMP_XAUTH_ATTRIB_MESSAGE,
	ISAKMP_XAUTH_ATTRIB_CHALLENGE,
	ISAKMP_XAUTH_ATTRIB_DOMAIN,
	ISAKMP_XAUTH_ATTRIB_STATUS,
	ISAKMP_XAUTH_ATTRIB_NEXT_PIN,
	ISAKMP_XAUTH_ATTRIB_ANSWER, /* TYPE .. ANSWER is excluded from dump */
	ISAKMP_MODECFG_ATTRIB_CISCO_BANNER = 0x7000,
	ISAKMP_MODECFG_ATTRIB_CISCO_SAVE_PW,
	ISAKMP_MODECFG_ATTRIB_CISCO_DEF_DOMAIN,
	ISAKMP_MODECFG_ATTRIB_CISCO_SPLIT_DNS,
	ISAKMP_MODECFG_ATTRIB_CISCO_SPLIT_INC,
	ISAKMP_MODECFG_ATTRIB_CISCO_UDP_ENCAP_PORT,
	ISAKMP_MODECFG_ATTRIB_CISCO_UNKNOWN, /* whatever 0x7006 is... */
	ISAKMP_MODECFG_ATTRIB_CISCO_DO_PFS,
	ISAKMP_MODECFG_ATTRIB_CISCO_FW_TYPE,
	ISAKMP_MODECFG_ATTRIB_CISCO_BACKUP_SERVER,
	ISAKMP_MODECFG_ATTRIB_CISCO_DDNS_HOSTNAME,
	ISAKMP_XAUTH_ATTRIB_CISCOEXT_VENDOR = 0x7d88 /* strange cisco things ... need docs! */
};

#endif
