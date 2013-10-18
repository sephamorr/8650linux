/*
 * Copyright (C) 2010-2012 Free Software Foundation, Inc.
 *
 * Author: Nikos Mavrogiannopoulos
 *
 * This file is part of GnuTLS.
 *
 * The GnuTLS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

#ifndef __GNUTLS_ABSTRACT_H
#define __GNUTLS_ABSTRACT_H

#include <stdarg.h>
#include <gnutls/gnutls.h>
#include <gnutls/x509.h>
#include <gnutls/pkcs11.h>
#include <gnutls/openpgp.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* Public key operations */

struct gnutls_pubkey_st;
typedef struct gnutls_pubkey_st *gnutls_pubkey_t;

struct gnutls_privkey_st;
typedef struct gnutls_privkey_st *gnutls_privkey_t;

typedef int (*gnutls_privkey_sign_func) (gnutls_privkey_t key,
                                         void *userdata,
                                         const gnutls_datum_t * raw_data,
                                         gnutls_datum_t * signature);
typedef int (*gnutls_privkey_decrypt_func) (gnutls_privkey_t key,
                                            void *userdata,
                                            const gnutls_datum_t * ciphertext,
                                            gnutls_datum_t * plaintext);

int gnutls_pubkey_init (gnutls_pubkey_t * key);
void gnutls_pubkey_deinit (gnutls_pubkey_t key);
int gnutls_pubkey_get_pk_algorithm (gnutls_pubkey_t key, unsigned int *bits);

int gnutls_pubkey_import_x509 (gnutls_pubkey_t key, gnutls_x509_crt_t crt,
                               unsigned int flags);
int gnutls_pubkey_import_pkcs11 (gnutls_pubkey_t key,
                                 gnutls_pkcs11_obj_t obj, unsigned int flags);
int gnutls_pubkey_import_openpgp (gnutls_pubkey_t key,
                                  gnutls_openpgp_crt_t crt,
                                  unsigned int flags);
int
gnutls_pubkey_import_privkey (gnutls_pubkey_t key, gnutls_privkey_t pkey,
                              unsigned int usage, unsigned int flags);


int gnutls_pubkey_get_preferred_hash_algorithm (gnutls_pubkey_t key,
                                                gnutls_digest_algorithm_t *
                                                hash, unsigned int *mand);

int gnutls_pubkey_get_pk_rsa_raw (gnutls_pubkey_t key,
                                  gnutls_datum_t * m, gnutls_datum_t * e);
int gnutls_pubkey_get_pk_dsa_raw (gnutls_pubkey_t key,
                                  gnutls_datum_t * p, gnutls_datum_t * q,
                                  gnutls_datum_t * g, gnutls_datum_t * y);
int gnutls_pubkey_get_pk_ecc_raw (gnutls_pubkey_t key, gnutls_ecc_curve_t *curve,
                              gnutls_datum_t * x, gnutls_datum_t * y);
int gnutls_pubkey_get_pk_ecc_x962 (gnutls_pubkey_t key, gnutls_datum_t* parameters,
                                   gnutls_datum_t * ecpoint);

int gnutls_pubkey_export (gnutls_pubkey_t key,
                          gnutls_x509_crt_fmt_t format,
                          void *output_data, size_t * output_data_size);

int gnutls_pubkey_get_key_id (gnutls_pubkey_t key, unsigned int flags,
                              unsigned char *output_data,
                              size_t * output_data_size);

int
gnutls_pubkey_get_openpgp_key_id (gnutls_pubkey_t key, unsigned int flags,
                          unsigned char *output_data,
                          size_t * output_data_size,
                          unsigned int *subkey);

int gnutls_pubkey_get_key_usage (gnutls_pubkey_t key, unsigned int *usage);
int gnutls_pubkey_set_key_usage (gnutls_pubkey_t key, unsigned int usage);

int gnutls_pubkey_import (gnutls_pubkey_t key,
                          const gnutls_datum_t * data,
                          gnutls_x509_crt_fmt_t format);


int gnutls_pubkey_import_pkcs11_url (gnutls_pubkey_t key, const char *url,
                                     unsigned int flags
                                     /* GNUTLS_PKCS11_OBJ_FLAG_* */ );
int gnutls_pubkey_import_dsa_raw (gnutls_pubkey_t key,
                                  const gnutls_datum_t * p,
                                  const gnutls_datum_t * q,
                                  const gnutls_datum_t * g,
                                  const gnutls_datum_t * y);
int gnutls_pubkey_import_rsa_raw (gnutls_pubkey_t key,
                                  const gnutls_datum_t * m,
                                  const gnutls_datum_t * e);

int
gnutls_pubkey_import_ecc_x962 (gnutls_pubkey_t key,
                               const gnutls_datum_t * parameters,
                               const gnutls_datum_t * ecpoint);

int
gnutls_pubkey_import_ecc_raw (gnutls_pubkey_t key,
                              gnutls_ecc_curve_t curve,
                              const gnutls_datum_t * x,
                              const gnutls_datum_t * y);

int
gnutls_pubkey_encrypt_data (gnutls_pubkey_t key, unsigned int flags,
                           const gnutls_datum_t * plaintext,
                           gnutls_datum_t * ciphertext);

int gnutls_x509_crt_set_pubkey (gnutls_x509_crt_t crt, gnutls_pubkey_t key);

int gnutls_x509_crq_set_pubkey (gnutls_x509_crq_t crq, gnutls_pubkey_t key);

#define GNUTLS_PUBKEY_VERIFY_FLAG_TLS_RSA 1
int
gnutls_pubkey_verify_hash (gnutls_pubkey_t key, unsigned int flags,
                           const gnutls_datum_t * hash,
                           const gnutls_datum_t * signature);

int
gnutls_pubkey_verify_hash2 (gnutls_pubkey_t key, 
                            gnutls_sign_algorithm_t algo,
                            unsigned int flags,
                            const gnutls_datum_t * hash,
                            const gnutls_datum_t * signature);

int
gnutls_pubkey_get_verify_algorithm (gnutls_pubkey_t key,
                                    const gnutls_datum_t * signature,
                                    gnutls_digest_algorithm_t * hash);

int gnutls_pubkey_verify_data (gnutls_pubkey_t pubkey,
                                   unsigned int flags,
                                   const gnutls_datum_t * data,
                                   const gnutls_datum_t * signature);
int
gnutls_pubkey_verify_data2 (gnutls_pubkey_t pubkey, 
                           gnutls_sign_algorithm_t algo,
                           unsigned int flags,
			   const gnutls_datum_t * data,
			   const gnutls_datum_t * signature);

/* Private key operations */

int gnutls_privkey_init (gnutls_privkey_t * key);
void gnutls_privkey_deinit (gnutls_privkey_t key);
int gnutls_privkey_get_pk_algorithm (gnutls_privkey_t key,
                                     unsigned int *bits);
gnutls_privkey_type_t gnutls_privkey_get_type (gnutls_privkey_t key);


#define GNUTLS_PRIVKEY_IMPORT_AUTO_RELEASE (1<<0)
#define GNUTLS_PRIVKEY_IMPORT_COPY (1<<1)
int gnutls_privkey_import_pkcs11 (gnutls_privkey_t pkey,
                                  gnutls_pkcs11_privkey_t key,
                                  unsigned int flags);
int gnutls_privkey_import_x509 (gnutls_privkey_t pkey,
                                gnutls_x509_privkey_t key,
                                unsigned int flags);
int gnutls_privkey_import_openpgp (gnutls_privkey_t pkey,
                                   gnutls_openpgp_privkey_t key,
                                   unsigned int flags);
int
gnutls_privkey_import_ext (gnutls_privkey_t pkey,
                           gnutls_pk_algorithm_t pk,
                           void* userdata,
                           gnutls_privkey_sign_func sign_func,
                           gnutls_privkey_decrypt_func decrypt_func,
                           unsigned int flags);

int gnutls_privkey_sign_data (gnutls_privkey_t signer,
                              gnutls_digest_algorithm_t hash,
                              unsigned int flags,
                              const gnutls_datum_t * data,
                              gnutls_datum_t * signature);

int gnutls_privkey_sign_hash (gnutls_privkey_t signer,
			      gnutls_digest_algorithm_t hash_algo,
			      unsigned int flags,
			      const gnutls_datum_t * hash_data,
			      gnutls_datum_t * signature);

int gnutls_privkey_decrypt_data (gnutls_privkey_t key,
                                 unsigned int flags,
                                 const gnutls_datum_t * ciphertext,
                                 gnutls_datum_t * plaintext);

int gnutls_x509_crt_privkey_sign (gnutls_x509_crt_t crt,
                                  gnutls_x509_crt_t issuer,
                                  gnutls_privkey_t issuer_key,
                                  gnutls_digest_algorithm_t dig,
                                  unsigned int flags);

int gnutls_x509_crl_privkey_sign (gnutls_x509_crl_t crl,
                                  gnutls_x509_crt_t issuer,
                                  gnutls_privkey_t issuer_key,
                                  gnutls_digest_algorithm_t dig,
                                  unsigned int flags);

int gnutls_x509_crq_privkey_sign (gnutls_x509_crq_t crq,
                                  gnutls_privkey_t key,
                                  gnutls_digest_algorithm_t dig,
                                  unsigned int flags);

/**
 * gnutls_pcert_st:
 * @pubkey: public key of parsed certificate.
 * @cert: certificate itself of parsed certificate
 * @type: type of certificate, a #gnutls_certificate_type_t type.
 *
 * A parsed certificate.
 */
typedef struct gnutls_pcert_st
{
  gnutls_pubkey_t pubkey;
  gnutls_datum_t cert;
  gnutls_certificate_type_t type;
} gnutls_pcert_st;

/* Do not initialize the "cert" element of
 * the certificate */
#define GNUTLS_PCERT_NO_CERT 1

int gnutls_pcert_import_x509 (gnutls_pcert_st* pcert,
	gnutls_x509_crt_t crt, unsigned int flags);

int
gnutls_pcert_list_import_x509_raw (gnutls_pcert_st * pcerts,
                             unsigned int *pcert_max,
                             const gnutls_datum_t * data,
                             gnutls_x509_crt_fmt_t format, unsigned int flags);

int gnutls_pcert_import_x509_raw (gnutls_pcert_st* pcert,
	const gnutls_datum_t* cert, 
	gnutls_x509_crt_fmt_t format, unsigned int flags);

int gnutls_pcert_import_openpgp_raw (gnutls_pcert_st* pcert,
	const gnutls_datum_t* cert, 
	gnutls_openpgp_crt_fmt_t format, 
	gnutls_openpgp_keyid_t keyid, unsigned int flags);

int gnutls_pcert_import_openpgp (gnutls_pcert_st* pcert,
	gnutls_openpgp_crt_t crt, unsigned int flags);

void gnutls_pcert_deinit (gnutls_pcert_st* pcert);

/* For certificate credentials */
  /* This is the same as gnutls_certificate_retrieve_function()
   * but retrieves a gnutls_pcert_st which requires much less processing
   * within the library.
   */
  typedef int gnutls_certificate_retrieve_function2 (gnutls_session_t,
                                                    const gnutls_datum_t *
                                                    req_ca_rdn,
                                                    int nreqs,
                                                    const
                                                    gnutls_pk_algorithm_t
                                                    * pk_algos,
                                                    int pk_algos_length,
                                                    gnutls_pcert_st **,
                                                    unsigned int *pcert_length,
                                                    gnutls_privkey_t *privkey);


void gnutls_certificate_set_retrieve_function2 (
   gnutls_certificate_credentials_t cred,
   gnutls_certificate_retrieve_function2 * func);

int
gnutls_certificate_set_key (gnutls_certificate_credentials_t res,
                            const char** names,
                            int names_size,
                            gnutls_pcert_st * pcert_list,
                            int pcert_list_size,
                            gnutls_privkey_t key);

#ifdef __cplusplus
}
#endif

#endif
