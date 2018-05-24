#ifndef _XROUTER_CONNECTOR_H_
#define _XROUTER_CONNECTOR_H_

#include <vector>
#include <string>
#include <cstdint>
#include "../json/json_spirit_reader_template.h"
#include "../json/json_spirit_writer_template.h"
#include "../json/json_spirit_utils.h"
#include "../xbridge/xbridgewallet.h"

namespace xrouter
{

class WalletConnectorXRouter : public xbridge::WalletParam
{
public:
    WalletConnectorXRouter();

    WalletConnectorXRouter & operator = (const WalletParam & other)
    {
        *(WalletParam *)this = other;
        return *this;
    }

    virtual std::string getBlockCount() const = 0;
    virtual std::string getBlockHash(const std::string & blockId) const = 0;
    virtual Object      getBlock(const std::string & blockHash) const = 0;
    virtual Object      getTransaction(const std::string & trHash) const = 0;
    virtual Array       getAllBlocks(const int number) const = 0;
    virtual Array       getAllTransactions(const std::string & account, const int number) const = 0;
    virtual std::string getBalance(const std::string & account) const = 0;
    virtual std::string getBalanceUpdate(const std::string & account, const int number) const = 0;
    virtual Array       getTransactionsBloomFilter(const int number) const = 0;
    virtual Object      sendTransaction(const std::string & transaction) const = 0;
    virtual Object      getPaymentAddress() const = 0;
};


} // namespace xrouter


#endif
