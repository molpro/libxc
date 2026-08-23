
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_xc_t_hle17_HO1D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)

    # Evaluate the data
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.121367412725877e+00, -1.121377005589001e+00, -1.121390624739196e+00, -1.121407612165537e+00, -1.121421823504313e+00, -1.121410258716251e+00, -1.121302745528854e+00, -1.120905054519747e+00, -1.119715613929550e+00, -1.116530821802253e+00, -1.108777691794367e+00, -1.092402445968564e+00, -1.065901047579018e+00, -1.010814809152951e+00, -8.638878336199638e-01, -6.198789627850672e-01, -4.077055819072170e-01, -1.705900339380621e-01, -2.808044626275824e-02, -1.333451786832218e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_xc_t_hle17_HO1D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)

    # Evaluate the data
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.485528151727275e+00, -1.485522881963250e+00, -1.485511893241156e+00, -1.485487679311324e+00, -1.485431738192373e+00, -1.485297806448351e+00, -1.484969759530037e+00, -1.484158084130197e+00, -1.482154588261112e+00, -1.477285349251595e+00, -1.465778423584738e+00, -1.439106345490136e+00, -1.375054942964160e+00, -1.258865780913978e+00, -1.088300074142780e+00, -7.797265508600805e-01, -3.778847477034740e-01, -2.192064736882503e-01, -3.741959848081446e-02, -1.777934394831684e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_HO1D_restr_1_vsigma():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)

    # Evaluate the data
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.262079791205219e-03, -5.285060007403776e-03, -5.322477031803169e-03, -5.383511846914666e-03, -5.483387757982411e-03, -5.647753389656535e-03, -5.921161084837932e-03, -6.385820950455843e-03, -7.212651933618525e-03, -8.841168306798529e-03, -1.277291528012668e-02, -2.498006516908955e-02, -5.498146955835492e-02, -6.101951964440794e-02, -3.588274108640026e-02, -2.414325086282913e-02, -1.652640386930903e-01, -1.106985609944958e-01, -3.807874609854346e-02, -1.314971319328799e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_HO1D_restr_1_vtau():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)

    # Evaluate the data
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.400891636450919e-03, 7.402074633783828e-03, 7.403993400797626e-03, 7.407119948124354e-03, 7.412298433833890e-03, 7.421301135412264e-03, 7.438978760070596e-03, 7.482857955294259e-03, 7.630090045852967e-03, 8.271526620237309e-03, 1.174207383481462e-02, 3.492256489188481e-02, 1.544630000031780e-01, 2.374239803413018e-01, 1.110488108013840e-01, 2.173940682966622e-02, 1.059343351036530e-03, 2.825093729040014e-06, 1.587121669488590e-10, 1.487255155767063e-17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
