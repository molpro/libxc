
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_xc_t_hle17_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)

    # Evaluate the data
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.291303538788638e-01, -9.291446630361390e-01, -9.291662757317611e-01, -9.291971147096285e-01, -9.292360642531150e-01, -9.292703714967409e-01, -9.292514615949601e-01, -9.290310792524913e-01, -9.282023162558314e-01, -9.257325442011617e-01, -9.192126609745309e-01, -9.036810583351821e-01, -8.714289395526170e-01, -8.155280031666244e-01, -7.059500473842385e-01, -5.182407952167375e-01, -3.557461793049819e-01, -1.417773653545933e-01, -2.320514716574713e-02, -1.101841325001933e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_xc_t_hle17_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)

    # Evaluate the data
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.235752809510497e+00, -1.235764761302276e+00, -1.235781799153142e+00, -1.235803268031389e+00, -1.235822000304637e+00, -1.235810769910068e+00, -1.235686328394892e+00, -1.235218682879385e+00, -1.233814924013885e+00, -1.230040910749547e+00, -1.220663352210262e+00, -1.198885449597087e+00, -1.149658337204091e+00, -1.042199663580950e+00, -8.915598501521735e-01, -6.099163078000580e-01, -3.499110453520717e-01, -1.843074640849932e-01, -3.092834625567316e-02, -1.469121021405479e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_HO2D_restr_1_vsigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)

    # Evaluate the data
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.295909308334998e-03, -1.307394959779031e-03, -1.326045892006665e-03, -1.356336951090146e-03, -1.405556091840956e-03, -1.485637756899034e-03, -1.616409632870563e-03, -1.832046642958366e-03, -2.196799007038745e-03, -2.854993693677584e-03, -4.239237542192921e-03, -8.156465238625364e-03, -2.283863377181963e-02, -5.435637325027821e-02, -4.826164776135040e-02, -5.694403456487820e-02, -2.188965015034176e-01, -1.124417611900089e-01, -3.809067768066064e-02, -1.314972256486504e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_HO2D_restr_1_vtau():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)

    # Evaluate the data
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.824147689530470e-03, 6.835758861310280e-03, 6.854455654626068e-03, 6.884409382920196e-03, 6.932014750003666e-03, 7.006747949421023e-03, 7.121983419319691e-03, 7.295702540996228e-03, 7.553704801005983e-03, 7.955753767228291e-03, 8.768625165388868e-03, 1.161140483181628e-02, 2.729250915153321e-02, 7.787415677490445e-02, 6.661343426969596e-02, 1.532764584595967e-02, 5.520263353144280e-04, 1.047674958039625e-06, 6.370757052790994e-11, 5.794506123555019e-18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
