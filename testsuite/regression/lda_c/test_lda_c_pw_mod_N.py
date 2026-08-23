
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pw_mod_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_mod", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.180998797102393e-01, -1.175098656683897e-01, -1.166632985667275e-01, -1.154500649694860e-01, -1.137144277587706e-01, -1.112379910507312e-01, -1.077185219407700e-01, -1.027472593834805e-01, -9.579996428731134e-02, -8.631564731164902e-02, -7.391993733580826e-02, -6.067077906068199e-02, -5.681198975192599e-02, -5.265634724580254e-02, -4.422983519335732e-02, -3.238742975177612e-02, -1.916574174460981e-02, -8.247096722489865e-03, -2.295605187484643e-03, -3.268687243322624e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pw_mod_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_mod", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.277416570792772e-01, -1.277434522715815e-01, -1.271403301119879e-01, -1.271441439847577e-01, -1.262765492418411e-01, -1.262847468725622e-01, -1.250364289365449e-01, -1.250543491325434e-01, -1.232571282758174e-01, -1.232972736749147e-01, -1.207055342244906e-01, -1.207987351135541e-01, -1.170450157355465e-01, -1.172729732972843e-01, -1.117736934591926e-01, -1.123755138011624e-01, -1.040699865335637e-01, -1.058444181504321e-01, -9.230185622377197e-02, -9.835066525527625e-02, -7.356782548221696e-02, -9.585790456820567e-02, -5.559478370961082e-02, -1.086550754653362e-01, -5.194250344256881e-02, -1.069281749064716e-01, -4.851370792892635e-02, -9.735894586759208e-02, -4.099340024899226e-02, -8.649750236487426e-02, -3.046515490330881e-02, -7.238330054904964e-02, -1.892155712197184e-02, -5.261438154735613e-02, -9.011218674264377e-03, -2.788619053766514e-02, -2.803604346374926e-03, -8.328843285553996e-03, -4.244147292130914e-04, -1.033092021712919e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pw_mod_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_mod", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.569829427500627e-04, -4.665477295877418e-04, 3.570015318265314e-04, 3.776084694888704e-04, -4.940033195089870e-04, 3.776504427750708e-04, 4.093214256009152e-04, -5.362873934013928e-04, 4.094198967676653e-04, 4.595141318379602e-04, -6.033770163557797e-04, 4.597582186192705e-04, 5.423083270636299e-04, -7.144659447549236e-04, 5.429631684017572e-04, 6.871508226807690e-04, -9.100000789757334e-04, 6.891191634140780e-04, 9.624493308515355e-04, -1.285564382500894e-03, 9.694149660124321e-04, 1.549129554141517e-03, -2.102219858291440e-03, 1.580272667090131e-03, 2.996672971505533e-03, -4.213995485155874e-03, 3.190512878313854e-03, 7.032668043750725e-03, -1.102480324866578e-02, 8.901193523369334e-03, 1.494139513221239e-02, -3.601587741371030e-02, 4.065876798637032e-02, 1.547535676684762e-02, -9.426444748864704e-02, 2.236223657733544e-01, 1.974624744647044e-02, -1.389911462216354e-01, 3.600425000817166e-01, 3.546359458794549e-02, -2.448694983359164e-01, 5.921031646235860e-01, 7.993710176046077e-02, -6.889518936485994e-01, 1.766977595570919e+00, 1.916782231179490e-01, -3.212407342989071e+00, 9.774052351176095e+00, -4.732286738971914e-01, -2.551221845393545e+01, 1.004665353687222e+02, -4.038128332234827e+01, -3.681842814446124e+02, 2.092446767289224e+03, -2.373001152657787e+03, -1.144653738308479e+04, 1.098366351571437e+05, -3.301227723667932e+05, -1.008237112822327e+06, 2.235274343746322e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
