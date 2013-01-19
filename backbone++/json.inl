namespace backbone {


template <typename Key, typename Value, typename Signals>
static inline ciere::json::value
to_json (
   backbone::map <Key, Value, Signals> const & m)
{
   ciere::json::object_t ret;

   for (auto const & i : m.map_)
   {
      ret[boost::lexical_cast <std::string> (i.first)] = to_json (i.second);
   }

   return ret;
}

template <typename Value, typename Signals>
static inline ciere::json::value
to_json (
   backbone::collection <Value, Signals> const & c)
{
   ciere::json::array_t ret;

   for (auto const & i : c.collection_)
   {
      ret.push_back (to_json (i));
   }

   return ret;
}

template <typename Model>
static inline ciere::json::value
to_json (
   Model const & m)
{
   json_writer w;
   boost::fusion::for_each_struct (m, w);

   return w.json_;
}

template <typename Key, typename Value>
void
json_writer::operator () (
   Key const &  key,
   Value &      data)
{
   json_[key] = 
      detail::json::writer::type_deduce <Value>::call (data);
}


};
