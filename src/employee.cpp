#include "employee.h"
#include "options.h"

std::vector<Options> Employee::permissions() {
  return {Options::changeArt,  Options::checkInvoice, Options::placeOrder,
          Options::changeCust, Options::addCust,      Options::updateStock, Options::exit};
}
