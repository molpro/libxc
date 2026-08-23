
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_xc_cam_lda0_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_cam_lda0", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.194092692438516e+00, -3.130448932350686e+00, -3.041236375375457e+00, -2.917588647687146e+00, -2.748968695034091e+00, -2.524282449136170e+00, -2.234591636370980e+00, -1.878160495428078e+00, -1.468118840946164e+00, -1.042936570226857e+00, -6.864968858659646e-01, -5.211187862810777e-01, -4.573238331280306e-01, -3.663500018217710e-01, -2.494643416013331e-01, -1.399625113189050e-01, -6.329471935307256e-02, -2.232248340674921e-02, -5.295875006754649e-03, -6.639587828625188e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_xc_cam_lda0_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_cam_lda0", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.244247299796746e+00, -4.244215317682920e+00, -4.159582288405323e+00, -4.159515477956388e+00, -4.040920670842591e+00, -4.040780501090444e+00, -3.876494400345469e+00, -3.876198450990168e+00, -3.652346551102851e+00, -3.651715790155433e+00, -3.353854382701326e+00, -3.352490926272850e+00, -2.969436342442501e+00, -2.966425209122052e+00, -2.497514080032920e+00, -2.490642371033824e+00, -1.957375689203547e+00, -1.940904373276463e+00, -1.404629841484333e+00, -1.362599208534596e+00, -9.538997231805901e-01, -8.466916741331911e-01, -7.371136401888597e-01, -5.549757395731063e-01, -6.457893213568109e-01, -4.812789579326879e-01, -5.163148769965955e-01, -3.954329958010406e-01, -3.493858760462397e-01, -2.735404186544476e-01, -1.921369344166184e-01, -1.603537132944908e-01, -8.295141201519267e-02, -8.358441101099479e-02, -2.855020519930189e-02, -3.562066253103702e-02, -6.863565104022968e-03, -9.437364472398024e-03, -8.754854283782379e-04, -1.106427728160676e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_xc_cam_lda0_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_cam_lda0", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.513814580050571e-02, -4.665477295877418e-04, -1.513837865906807e-02, -1.576278514453622e-02, -4.940033195089870e-04, -1.576330210757581e-02, -1.670532548710992e-02, -5.362873934013928e-04, -1.670650917528135e-02, -1.815746410236846e-02, -6.033770163557797e-04, -1.816029750540599e-02, -2.046232118154361e-02, -7.144659447549236e-04, -2.046955113833339e-02, -2.427935912234362e-02, -9.100000789757334e-04, -2.429958420190698e-02, -3.099370963787160e-02, -1.285564382500894e-03, -3.105828187924214e-02, -4.384729699793044e-02, -2.102219858291440e-03, -4.409646450687853e-02, -7.141887426760898e-02, -4.213995485155874e-03, -7.267573285775404e-02, -1.384803011682472e-01, -1.102480324866578e-02, -1.474916599738393e-01, -2.981319001173260e-01, -3.601587741371030e-02, -3.826569457499612e-01, -4.925601887918973e-01, -9.426444748864704e-02, -8.895445154908357e-01, -6.375661596301583e-01, -1.389911462216354e-01, -1.170823361230743e+00, -9.860184166851035e-01, -2.448694983359164e-01, -1.703854671263052e+00, -2.082410169225611e+00, -6.889518936485994e-01, -3.331647382230471e+00, -6.289057375495586e+00, -3.212407342989071e+00, -7.093228995306216e+00, -2.808567622692624e+01, -2.551221845393545e+01, 6.875343372969027e+00, -2.601065669788392e+02, -3.681842814446124e+02, 7.505113706738175e+02, -7.212528220989534e+03, -1.144653738308479e+04, 4.506555675800298e+04, -7.212463378551023e+05, -1.008237112822327e+06, 7.556225603914922e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
