namespace backbone { namespace detail {


template <typename Signals>
inline observable <Signals>::observable ()
   : signals_ (new Signals ())
{
}


template <typename Signals>
template <typename Signal>
inline void
observable <Signals>::trigger (
   Signal &     signal)
{
   signals_->all ();
   signal ();
}


template <typename Signals>
template <typename Signal, typename Value>
inline void
observable <Signals>::trigger (
   Signal &     signal,
   Value &      value)
{
   signals_->all ();
   signal (value);
}

template <typename Signals>
inline Signals &
observable <Signals>::signals ()
{
   return *signals_;
}


}; };
