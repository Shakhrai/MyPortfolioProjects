﻿using PublicTransport.Data.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PublicTransport.Data.Repositories.Abstract
{
        public interface IServiceItemsRepository
        {
            IQueryable<ServiceItem> GetServiceItems();
            ServiceItem GetServiceItemById(Guid id);
            void SaveServiceItem(ServiceItem entity);
            void DeleteServiceItem(Guid id);
        }
}
