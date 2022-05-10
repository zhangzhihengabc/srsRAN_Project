
#ifndef SRSGNB_MAC_CONFIG_INTERFACES_H
#define SRSGNB_MAC_CONFIG_INTERFACES_H

#include "srsgnb/mac/mac.h"
#include "srsgnb/support/async/async_task.h"

namespace srsgnb {

class mac_ul_configurator
{
public:
  virtual ~mac_ul_configurator()                                                             = default;
  virtual async_task<bool> add_ue(const mac_ue_create_request_message& msg)                  = 0;
  virtual async_task<bool> reconfigure_ue(const mac_ue_reconfiguration_request_message& msg) = 0;
  virtual async_task<void> remove_ue(const mac_ue_delete_request_message& msg)               = 0;
  virtual void             flush_ul_ccch_msg(du_ue_index_t ue_index, byte_buffer pdu)        = 0;
};

class mac_dl_configurator : public mac_cell_manager
{
public:
  virtual ~mac_dl_configurator()                                                             = default;
  virtual async_task<bool> add_ue(const mac_ue_create_request_message& msg)                  = 0;
  virtual async_task<bool> reconfigure_ue(const mac_ue_reconfiguration_request_message& msg) = 0;
  virtual async_task<void> remove_ue(const mac_ue_delete_request_message& msg)               = 0;
};

class mac_ctrl_configurator
{
public:
  virtual ~mac_ctrl_configurator()                                                      = default;
  virtual bool add_ue(du_ue_index_t ue_index, rnti_t rnti, du_cell_index_t pcell_index) = 0;
  virtual void remove_ue(du_ue_index_t ue_index)                                        = 0;
};

} // namespace srsgnb

#endif // SRSGNB_MAC_CONFIG_INTERFACES_H
