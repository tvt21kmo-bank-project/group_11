const db= require('../database');
// luodaan bank-niminen objekti
// ja sen sisään tarvittavat funktiot
const bank = {

    debit: function(postData, callback){
        return db.query('call debit_nosto(?,?,?)',
        [postData.idTili, postData.idKortti, postData.Summa],callback);
    },
    credit: function(postData, callback){
        return db.query('call credit_nosto(?,?,?)',
        [postData.idTili, postData.idKortti, postData.Summa],callback);

    }
};
//exportilla viedään ulost bank objekti
module.exports = bank;