#include "GBHigh.h"
#ifdef TANDEM_VERIFICATION
void GBHigh::check_arg_1_TREADY(RTLVerilated* v) {
  if (GBHigh_arg_1_TREADY != v->v_top->arg_1_TREADY)
    throw GBHighException("arg_1_TREADY unequal.");
}
void GBHigh::check_arg_0_TVALID(RTLVerilated* v) {
  /*
  if (GBHigh_arg_0_TVALID != v->v_top->arg_0_TVALID)
    throw GBHighException("arg_0_TVALID unequal.");
  */
}
void GBHigh::check_arg_0_TDATA(RTLVerilated* v) {
  //std::cout << (uint32_t) GBHigh_arg_0_TDATA << ":" << (uint32_t) v->v_top->arg_0_TDATA << std::endl;
  if (!((GBHigh_arg_0_TDATA <= v->v_top->arg_0_TDATA + 1) && (GBHigh_arg_0_TDATA >= v->v_top->arg_0_TDATA - 1)))
    //std::cout << "arg_0_TDATA unequal" << std::endl;
    throw GBHighException("arg_0_TDATA unequal.");  
}
void GBHigh::check_st_ready(RTLVerilated* v) {}
void GBHigh::check_cur_pic(RTLVerilated* v) {}
void GBHigh::check_ram_x(RTLVerilated* v) {
  /* if (GBHigh_ram_x !=
    v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0->hls_target_call_U0->hls_target_call_Loop_LB2D_buf_proc_U0->col_reg_349)
    throw GBHighException("ram_x unequal."); */
}
void GBHigh::check_ram_y(RTLVerilated* v) {
  if (GBHigh_ram_y !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
              ->hls_target_call_U0->hls_target_call_Loop_LB2D_buf_proc_U0
              ->row_1_reg_693 -
          1)
    throw GBHighException("ram_y unequal.");
}
void GBHigh::check_ram_w(RTLVerilated* v) {
  if (GBHigh_ram_w !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_buf_proc_U0
          ->write_idx_1_1_reg_338)
    throw GBHighException("ram_w unequal.");
}
void GBHigh::check_gbit(RTLVerilated* v) {}
void GBHigh::check_stencil0(RTLVerilated* v) {
  for (int i  = 7; i > -1; i--) {
    int idx = i / 4;
    int jdx = i % 4;
    int ila_shift = (8 - i) * 8;
    uint8_t v_1 = ((uint8_t) ((GBHigh_stencil0 >> (ila_shift)) & (0xff)));
    uint8_t v_2 = (v->ref_stencils) ? (v->ref_stencils[idx] >> (jdx*8)) : (v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil0[idx] >> (jdx * 8));
    if (v_1 != v_2) {
      std::cout << i << (uint32_t) v_1 << (uint32_t) v_2 << std::endl;
      throw GBHighException("stencil0 unequal.");
    }
  }    
  /*
  if ((GBHigh_stencil0 >> 0) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil0[0])
    throw GBHighException("stencil0 unequal.");
  if ((GBHigh_stencil0 >> 32) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil0[1])
    throw GBHighException("stencil0 unequal.");
  if ((GBHigh_stencil0 >> 64) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil0[2])
    throw GBHighException("stencil0 unequal.");
  */  
}
void GBHigh::check_stencil1(RTLVerilated* v) {
  for (int i  = 7; i > -1; i--) {
    int idx = i / 4;
    int jdx = i % 4;
    int ila_shift = (8 - i) * 8;
    uint8_t v_1 = ((uint8_t) ((GBHigh_stencil1 >> (ila_shift)) & (0xff)));
    uint8_t v_2 = (v->ref_stencils) ? (v->ref_stencils[3 + idx] >> (jdx*8)) : v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil1[idx] >> (jdx * 8);
    if (v_1 != v_2) {
      std::cout << (uint32_t) v_1 << (uint32_t) v_2 << std::endl;
      throw GBHighException("stencil1 unequal.");
    }
  }  
  /*
  if ((GBHigh_stencil1 >> 0) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil1[0])
    throw GBHighException("stencil1 unequal.");
  if ((GBHigh_stencil1 >> 32) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil1[1])
    throw GBHighException("stencil1 unequal.");
  if ((GBHigh_stencil1 >> 64) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil1[2])
    throw GBHighException("stencil1 unequal.");
  */
}
void GBHigh::check_stencil2(RTLVerilated* v) {
  for (int i  = 7; i > -1; i--) {
    int idx = i / 4;
    int jdx = i % 4;
    int ila_shift = (8 - i) * 8;
    uint8_t v_1 = ((uint8_t) ((GBHigh_stencil2 >> (ila_shift)) & (0xff)));
    uint8_t v_2 = (v->ref_stencils) ? (v->ref_stencils[6 + idx] >> (jdx*8)) : v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil2[idx] >> (jdx * 8);
    if (v_1 != v_2) {
      std::cout << (uint32_t) v_1 << (uint32_t) v_2 << std::endl;
      throw GBHighException("stencil2 unequal.");
    }
  }
  /*
  if ((GBHigh_stencil2 >> 0) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil2[0])
    throw GBHighException("stencil2 unequal.");
  if ((GBHigh_stencil2 >> 32) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil2[1])
    throw GBHighException("stencil2 unequal.");
  if ((GBHigh_stencil2 >> 64) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil2[2])
    throw GBHighException("stencil2 unequal.");
  */
}
void GBHigh::check_stencil3(RTLVerilated* v) {
  for (int i  = 7; i > -1; i--) {
    int idx = i / 4;
    int jdx = i % 4;
    int ila_shift = (8 - i) * 8;
    uint8_t v_1 = ((uint8_t) ((GBHigh_stencil3 >> (ila_shift)) & (0xff)));
    uint8_t v_2 = (v->ref_stencils) ? (v->ref_stencils[9 + idx] >> (jdx*8)) : v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil3[idx] >> (jdx * 8);
    if (v_1 != v_2) {
      std::cout << (uint32_t) v_1 << (uint32_t) v_2 << std::endl;
      throw GBHighException("stencil3 unequal.");
    }
  }  
  /*
  if ((GBHigh_stencil3 >> 0) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil3[0])
    throw GBHighException("stencil3 unequal.");
  if ((GBHigh_stencil3 >> 32) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil3[1])
    throw GBHighException("stencil3 unequal.");
  if ((GBHigh_stencil3 >> 64) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil3[2])
    throw GBHighException("stencil3 unequal.");
  */
}
void GBHigh::check_stencil4(RTLVerilated* v) {
  for (int i  = 7; i > -1; i--) {
    int idx = i / 4;
    int jdx = i % 4;
    int ila_shift = (8 - i) * 8;
    uint8_t v_1 = ((uint8_t) ((GBHigh_stencil4 >> (ila_shift)) & (0xff)));
    uint8_t v_2 = (v->ref_stencils) ? (v->ref_stencils[12 + idx] >> (jdx*8)) : v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil4[idx] >> (jdx * 8);
    if (v_1 != v_2) {
      std::cout << (uint32_t) v_1 << (uint32_t) v_2 << std::endl;
      throw GBHighException("stencil4 unequal.");
    }
  }  
  /*
  if ((GBHigh_stencil4 >> 0) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil4[0])
    throw GBHighException("stencil4 unequal.");
  if ((GBHigh_stencil4 >> 32) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil4[1])
    throw GBHighException("stencil4 unequal.");
  if ((GBHigh_stencil4 >> 64) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil4[2])
    throw GBHighException("stencil4 unequal.");
  */
}
void GBHigh::check_stencil5(RTLVerilated* v) {
  for (int i  = 7; i > -1; i--) {
    int idx = i / 4;
    int jdx = i % 4;
    int ila_shift = (8 - i) * 8;
    uint8_t v_1 = ((uint8_t) ((GBHigh_stencil5 >> (ila_shift)) & (0xff)));
    uint8_t v_2 = (v->ref_stencils) ? (v->ref_stencils[15 + idx] >> (jdx*8)) : v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil5[idx] >> (jdx * 8);
    if (v_1 != v_2) {
      std::cout << (uint32_t) v_1 << (uint32_t) v_2 << std::endl;
      throw GBHighException("stencil5 unequal.");
    }  
  }  
  /*
  if ((GBHigh_stencil5 >> 0) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil5[0])
    throw GBHighException("stencil5 unequal.");
  if ((GBHigh_stencil5 >> 32) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil5[1])
    throw GBHighException("stencil5 unequal.");
  if ((GBHigh_stencil5 >> 64) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil5[2])
    throw GBHighException("stencil5 unequal.");
  */
}
void GBHigh::check_stencil6(RTLVerilated* v) {
  for (int i  = 7; i > -1; i--) {
    int idx = i / 4;
    int jdx = i % 4;
    int ila_shift = (8 - i) * 8;
    uint8_t v_1 = ((uint8_t) ((GBHigh_stencil6 >> (ila_shift)) & (0xff)));
    uint8_t v_2 = (v->ref_stencils) ? (v->ref_stencils[18 + idx] >> (jdx*8)) : v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil6[idx] >> (jdx * 8);
    if (v_1 != v_2) {
      std::cout << (uint32_t) v_1 << (uint32_t) v_2 << std::endl;
      throw GBHighException("stencil6 unequal.");
    }

  }
  /*  
  if ((GBHigh_stencil6 >> 0) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil6[0])
    throw GBHighException("stencil6 unequal.");
  if ((GBHigh_stencil6 >> 32) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil6[1])
    throw GBHighException("stencil6 unequal.");
  if ((GBHigh_stencil6 >> 64) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil6[2])
    throw GBHighException("stencil6 unequal.");
  */
}
void GBHigh::check_stencil7(RTLVerilated* v) {
  for (int i  = 7; i > -1; i--) {
    int idx = i / 4;
    int jdx = i % 4;
    int ila_shift = (8 - i) * 8;
    uint8_t v_1 = ((uint8_t) ((GBHigh_stencil7 >> (ila_shift)) & (0xff)));
    uint8_t v_2 = (v->ref_stencils) ? (v->ref_stencils[21 + idx] >> (jdx*8)) : (v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil7[idx] >> (jdx * 8));
    if (v_1 != v_2) {
      std::cout << i << " " << (uint32_t) v_1 << (uint32_t) v_2 << std::endl;
      throw GBHighException("stencil7 unequal.");
    }
  }
  /*
  std::cout << std::hex << "stencil7 " << GBHigh_stencil7 << " : "
            << v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil7[2]
            << v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil7[1]
            << v->v_top->hls_target->hls_target_linebuffer_1_U0
                   ->hls_target_linebuffer_U0->hls_target_call_U0
                   ->hls_target_call_Loop_LB2D_shift_proc_U0->stencil7[0]
            << std::endl;

  if ((GBHigh_stencil7 >> 0) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil7[0])
    throw GBHighException("stencil7 unequal.");
  if ((GBHigh_stencil7 >> 32) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil7[1])
    throw GBHighException("stencil7 unequal.");
  if ((GBHigh_stencil7 >> 64) % (1ll << 32) !=
      v->v_top->hls_target->hls_target_linebuffer_1_U0->hls_target_linebuffer_U0
          ->hls_target_call_U0->hls_target_call_Loop_LB2D_shift_proc_U0
          ->stencil7[2])
    throw GBHighException("stencil7 unequal.");
    */
}
void GBHigh::check_stencil8(RTLVerilated* v) {}
void GBHigh::tandem_instr_Write(RTLVerilated* v) {
  // check_arg_0_TDATA(v);
  check_arg_0_TVALID(v);
  check_arg_1_TREADY(v);
  check_cur_pic(v);
  check_ram_w(v);
  check_ram_x(v);
  check_ram_y(v);
  /*
  check_stencil0(v);
  check_stencil1(v);
  check_stencil2(v);
  check_stencil3(v);
  check_stencil4(v);
  check_stencil5(v);
  check_stencil6(v);
  check_stencil7(v);
  check_stencil8(v);
  */
}
void GBHigh::tandem_instr_Read(RTLVerilated* v) {
  check_arg_0_TDATA(v);
  check_arg_0_TVALID(v);
  check_arg_1_TREADY(v);
  check_cur_pic(v);
  check_gbit(v);
  check_ram_w(v);
  check_ram_x(v);
  check_ram_y(v);
  /*
  check_stencil0(v);
  check_stencil1(v);
  check_stencil2(v);
  check_stencil3(v);
  check_stencil4(v);
  check_stencil5(v);
  check_stencil6(v);
  check_stencil7(v);
  check_stencil8(v);
  */
}
#endif
