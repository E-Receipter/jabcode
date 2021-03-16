/*
Encryption and Decryption functions

(Read jabcode.h in src/jabcode to understand jab_data)
*/

#include "jabcode.h"
#include "encryption.h"

/*
@brief encrypt data using given key
*/
jab_data* RG_encrypt(jab_data* key,jab_data* data){
    // Encrypt enc_data -> data using enc_data -> key
    return data;
}

/*
@brief decrypt data using the given key
*/
jab_data* RG_decrypt(jab_data* key,jab_data* data){
    return data;
}

/*
@brief generate a signature for the given data
*/
jab_data* RG_sign(jab_data* data){
    return data;
}