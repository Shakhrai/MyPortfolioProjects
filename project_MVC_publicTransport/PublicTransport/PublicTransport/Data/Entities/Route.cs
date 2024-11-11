using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PublicTransport.Models
{
    public class Route
    {
        [Key]
        [Required]
        public Guid routeId { get; set; }
        [Display(Name = "Название маршрута")]
        public string routeName { get; set; }
        [Display(Name = "Город маршрута")]
        public string routeTown { get; set; }
        [Display(Name = "Количество остановок")]
        public int routeCountStop { get; set; }
        [Display(Name = "Id транспорта")]
        public int transportId { get; set; }
        [Display(Name = "Номер транспорта")]
        public string transportName { get; set; }
        public Transport Transport { get; set; }
    }
}
