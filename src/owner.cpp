#include "owner.h"

std::vector<Options> Owner::permissions() {
  return {Options::addArt,       Options::deleteArt,  Options::changeArt,
          Options::checkInvoice, Options::placeOrder, Options::deleteCust,
          Options::changeCust,   Options::addCust,    Options::updateStock, Options::exit};
}
